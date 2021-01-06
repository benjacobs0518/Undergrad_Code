#include "gameWindow.h"
#include "gameController.h"
#include "ui_gameWindow.h"
#include "mainMenu.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene; //set up main scene
    view = ui->snakeView; //set up main view
    view->setScene(scene); //add main scene to the main view
    scene->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    game = new GameController(*scene, this);

    QPixmap background(CELL_SIZE, CELL_SIZE);
    QPainter painter(&background);
    painter.setBrush(QBrush(QColor(108,161,81)));
    painter.drawRect(0, 0, CELL_SIZE, CELL_SIZE);
    view->setBackgroundBrush(QBrush(background));

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::newGame()
{
    QTimer::singleShot(0, game, SLOT(gameOver()));
}



