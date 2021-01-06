#include "dialog.h"
#include "ui_dialog.h"
#include "head.h"

#include <QObject>

Dialog::Dialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300); //

    QPen mypen = QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    Head *head = new Head();
    scene->addItem(head);

    head->setFocus();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);



}

Dialog::~Dialog()
{
    delete ui;
}

