#include <QDebug>
#include <QTimer>
#include <QTime>

#include "shape.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));


    QGraphicsScene * scene = new QGraphicsScene;
    view = ui->graphicsView;
    view->setScene(scene);
    // make the scene the same size as the view containing it
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());


    // make an outline
//    scene->addRect(0, 0, view->frameSize().width(), view->frameSize().height());


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_timer_fired);
    timer->start(1000);
    time_steps_ = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << value;
    std::string as_str = std::to_string(value);
    ui->sliderLabel->setText(QString(as_str.c_str()));
}

void MainWindow::on_timer_fired() {
    qDebug() << "timer fired!";

    if (points_.size() == 5) {
       ShapeObj * first = points_[0];
       points_.erase(points_.begin());
       view->scene()->removeItem(first);
    }

    ShapeObj * so = new ShapeObj(time_steps_ * 20, 0);
    view->scene()->addItem(so);
    points_.push_back(so);
    time_steps_++;

//    std::string as_str = std::to_string(ui->horizontalSlider->value());
//    ui->sliderLabel;
//    TakeStep();
}



