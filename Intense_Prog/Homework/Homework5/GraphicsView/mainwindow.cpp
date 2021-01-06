#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <thread>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    scene = new QGraphicsScene(this);
    ui->mainView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(6);

    ellipse = scene->addEllipse(10,10,100,100,blackpen,redBrush);
    rectangle = scene->addRect(-100,-100, 50,50,blackpen,blueBrush);
    */

    main_scene = new QGraphicsScene;
    QGraphicsView * viewMain = ui->mainView;
    viewMain->setScene(main_scene); //add main scene to the main view
    viewMain->setSceneRect(0,0,viewMain->frameSize().width(),viewMain->frameSize().height());

    int temp_width = Cell::get_width(); //assign temp width value
    Cell offset(temp_width, temp_width, false); //set offset values to cell
    Cell* temp; //create temp cell pointer

    for (int x = offset.get_x(); x <= 30*temp_width; x = x + temp_width) { //loop through width
        for (int y = offset.get_y(); y <= 20*temp_width; y = y + temp_width) { // loop through height
            double r = (rand() % 3); //chance in being born
            if (r == 1) {
                temp = new Cell(x, y, false);
            }
            else {
                temp = new Cell(x, y, false);
            }
            main_scene->addItem(temp); //add cell to scene
            //grid_.push_back(temp); //add cell to grid vector
        }
    }

    Cell* head = new Cell(88,88,true);
    main_scene->addItem(head);
    head->setFocus();

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( head->move() ) );

    m_timer.start( 50 );


}

MainWindow::~MainWindow()
{
    delete ui;
}

