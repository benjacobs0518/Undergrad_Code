#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QAction>
#include <iostream>
#include <QPainter>
#include <QTimer>
#include <QDebug>

#include "gameController.h"

const int CELL_SIZE = 22;


class GameController;

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    void setName(QString n) {p1_=n;}
    void setName2(QString n) {p2_=n;}
    ~GameWindow();

private slots:
    void newGame();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;

    QString p1_;
    QString p2_;

    void initSceneBackground();
};
#endif // GAMEWINDOW_H
