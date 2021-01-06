#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    main_scene = new QGraphicsScene;
    QGraphicsView * viewMain = ui->mainView;
    viewMain->setScene(main_scene); //add main scene to the main view
    viewMain->setSceneRect(0,0,viewMain->frameSize().width(),viewMain->frameSize().height());

    int temp_width = Cell::get_width(); //assign temp width value
    Cell offset(temp_width, temp_width); //set offset values to cell
    Cell* temp; //create temp cell pointer

    for (int x = offset.get_x(); x <= 30*temp_width; x = x + temp_width) { //loop through width
        for (int y = offset.get_y(); y <= 15*temp_width; y = y + temp_width) { // loop through height
            double r = (rand() % 3); //chance in being born
            if (r == 1) {
                temp = new Cell(x, y);
            }
            else {
                temp = new Cell(x, y);
            }
            main_scene->addItem(temp); //add cell to scene
            grid_.push_back(temp); //add cell to grid vector
        }
    }

    head_= new Cell(15*temp_width,4*temp_width);
    head_->setBody();
    main_scene->addItem(head_);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e) {

    QString text = ui->label->text();
    text += char(e->key());
    ui->label->setText(text);
    move_ = char(e->key());
    head_->Step(move_);

}


