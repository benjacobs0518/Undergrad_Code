#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <thread>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include "histogram.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedWidth(750); //fix window size for rules display

    main_scene = new QGraphicsScene; //set up main scene
    histogram_scene = new QGraphicsScene; //set up histogram scene

    QGraphicsView * viewMain = ui->mainView; //adds pointer value to main view
    QGraphicsView * viewHist = ui->histogramView; //adds pointer value to histogram view

    viewMain->setScene(main_scene); //add main scene to the main view
    viewHist->setScene(histogram_scene); //add histogram scene to the hist view

    viewMain->setSceneRect(0,0,viewMain->frameSize().width(),viewMain->frameSize().height()); //set area for main view
    viewHist->setSceneRect(0,0,viewHist->frameSize().width(),viewHist->frameSize().height()); //set area for hist view



    int temp_width = Cell::get_width(); //assign temp width value
    Cell offset(false, temp_width, temp_width); //set offset values to cell
    Cell* temp; //create temp cell pointer

    for (int x = offset.get_x(); x <= 30*temp_width; x = x + temp_width) { //loop through width
        for (int y = offset.get_y(); y <= 15*temp_width; y = y + temp_width) { // loop through height
            double r = (rand() % 3); //chance in being born
            if (r == 1) {
                temp = new Cell(true, x, y);
                population_++;
            }
            else {
                temp = new Cell(false, x, y);
            }
            main_scene->addItem(temp); //add cell to scene
            grid_.push_back(temp); //add cell to grid vector
        }
    }

    for (Cell* c : grid_) { //add a step for all cells and add up total surviving
        c->set_neighbors(); //set all neighboring coords
    }

    double percentAlive = (double(population_) / double(total_))*100; //calculate percentage

    string populationString = "Population: " + to_string(population_) + " (" + to_string(int(percentAlive)) + "%)"; //population percent string
    ui->populationLabel->setText(QString::fromStdString(populationString)); //add population percent string into the text field

    y_offset_ = viewHist->frameSize().height()-2; //offset for y on histogram
    h_offset_ = viewHist->frameSize().height(); //offset for height on histogram
    maxSize_ =  viewHist->frameSize().width() / Histogram::get_width(); //the total amount of bars allowed on the view

    Histogram* initBar = new Histogram(0, y_offset_, int(0.5 * h_offset_)); //create first histogram
    hists_.push_back(initBar); //add histogram to vector
    histogram_scene->addItem(initBar); //add histogram to scene

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Turn() {
    if(play_ == true){
        std::this_thread::sleep_for(std::chrono::milliseconds(500-speed_)); //sleep inbetween steps
    }

    int neighbors; //amount of living neighbors
    int popCount = 0; //population alive

    for (Cell* c : grid_) { //scan through all cells
        neighbors = GetNeighbors(c); //get total living neighbors for individual cells

        if (c->is_alive()) {
            if (neighbors < 2) { //if alive and has less than two neighbors
                c->condition_changed_ = true;
            }
            else if (neighbors > 3) {//if alive and has more than three neighbors
                c->condition_changed_ = true;
            }
        }
        else if ( neighbors == 3) { //if dead and has three neighbors
           c->condition_changed_ = true;
        }
    }

    for (Cell* c : grid_) { //add a step for all cells and add up total surviving
        c->Step();
        if (c->is_alive()) {
            popCount++;
        }
    }

    population_ = popCount; //update population
    turn_count++; //add one to turn
    double percentAlive = (double(population_) / double(total_));

    string turnString = "Turn: " + to_string(turn_count) ; //turn label
    string populationString = "Population: " + to_string(population_) + " (" + to_string(int(percentAlive*100)) + "%)"; //percent string

    ui->turnLabel->setText(QString::fromStdString(turnString));//update turn label
    ui->populationLabel->setText(QString::fromStdString(populationString)); //update population label

    Histogram* temp_hist;
    if (int(hists_.size()) > maxSize_) {//if the histogram exceedes max size
        int prev = 0; //previous x value

        for (Histogram* h : hists_) {
            h->set_x(-1 * h->get_width()); // set each bar back -1 position
            prev = h->get_x();
        }

        temp_hist = new Histogram(prev+Histogram::get_width() , y_offset_, int(percentAlive * h_offset_)); //create new historgam
    }
    else {
        temp_hist = new Histogram(turn_count*Histogram::get_width(), y_offset_, int(percentAlive * h_offset_)); //create new historgam at open location
    }

    hists_.push_back(temp_hist); //add histogram to vector
    histogram_scene->addItem(temp_hist); //add histogram to scene
    histogram_scene->update(); //update histogram

}

void MainWindow::on_stepButton_clicked()
{
    Turn(); //take turn
    QCoreApplication::processEvents(); //process changes
}

int MainWindow::GetNeighbors(Cell* c) {
    int neighborCount = 0; //amount of living neighbors
    tuple<int,int> coords; //temp coords
    int x_temp;
    int y_temp;

    vector< tuple<int, int> > neighbors = c->get_neighbors();
    for(int i = 0; i < 8; i++){ //totals up all of the neighbors
        coords = neighbors.at(i); //get all neigbor coords
        x_temp = get<0>(coords);
        y_temp = get<1>(coords);
        if(livingCell(x_temp, y_temp)){
            neighborCount++;
        }
    }
    return neighborCount; //return amount of living neigbors
}

bool MainWindow::livingCell(int x, int y) { //checks to see if cell is alive
    for (Cell* c : grid_) {
        if (c->get_xadj() == x && c->get_yadj() == y) {
            return c->is_alive(); //return true if found
        }
    }
    return false;
}

void MainWindow::on_speedSlider_sliderMoved(int position)
{
    speed_ = position; //assign speed value to the position of the slider
    float temp = 1.0 - (((speed_-251)/2)*.01); //float point value for slider speed
    ui->speedLabel->setNum(temp);//add string to label
}


void MainWindow::on_playButton_clicked()
{
    play_ = true; //allows for delay to activate
    while(!paused_){ //while the pause button isn't played
        Turn();
        QCoreApplication::processEvents();
    }
    paused_ = !paused_; //paused
}


void MainWindow::on_pauseButton_clicked()
{
    play_ = false; //stop delay
    paused_ = true; //stop loop
}

void MainWindow::on_thanosSnap_clicked()
{
    bool select = true; //selected person to die
    for (Cell* c : grid_) {
        if(c->is_alive()){
            select = !select; //every other person dies because of thanos 50% rule
            if (select) {
                 c->condition_changed_ = true; //make dead
                 c->Step(); //update values
            }
        }
    }

    population_ =  population_/2; //divide population by half
    turn_count++; //add one to the turn count
    double percentAlive = (double(population_) / double(total_)); //percent of people alive

    string turnString = "Turn: " + to_string(turn_count) ; //turn label
    string populationString = "Population: " + to_string(population_) + " (" + to_string(int(percentAlive*100)) + "%)";//population label

    ui->turnLabel->setText(QString::fromStdString(turnString)); //add text to label
    ui->populationLabel->setText(QString::fromStdString(populationString)); //add text to label

    Histogram* temp_hist;
    if (int(hists_.size()) > maxSize_) {//if the histogram exceedes max size
        int prev = 0; //previous x value

        for (Histogram* h : hists_) {
            h->set_x(-1 * h->get_width()); // set each bar back -1 position
            prev = h->get_x();
        }

        temp_hist = new Histogram(prev+Histogram::get_width() , y_offset_, int(percentAlive * h_offset_)); //create new historgam
    }
    else {
        temp_hist = new Histogram(turn_count*Histogram::get_width(), y_offset_, int(percentAlive * h_offset_)); //create new historgam at open location
    }

    hists_.push_back(temp_hist); //add histogram to vector
    histogram_scene->addItem(temp_hist); //add histogram to scene
    histogram_scene->update(); //update histogram
}


void MainWindow::on_ruleButton_clicked()
{
    if(ui->playButton->isEnabled() == false){ //enables all buttons if disabled
        ui->pauseButton->setEnabled(true);
        ui->playButton->setEnabled(true);
        ui->thanosSnap->setEnabled(true);
        ui->stepButton->setEnabled(true);
    }
    else{ //disables all buttons if enabled
        ui->pauseButton->setEnabled(false);
        ui->playButton->setEnabled(false);
        ui->thanosSnap->setEnabled(false);
        ui->stepButton->setEnabled(false);
    }

    if (!rulesEnabled) { //show rules
        ui->rulesText->show();
        rulesEnabled = true;
        this->setFixedWidth(1100); //resize to fit rules
    }
    else {
        ui->rulesText->hide(); //hide rules
        rulesEnabled = false;
        this->setFixedWidth(750); //reset size to hide rules
    }
}
