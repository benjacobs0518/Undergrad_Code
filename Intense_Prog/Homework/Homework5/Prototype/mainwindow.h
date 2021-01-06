#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QWidget>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *main_scene; //main scene is for the grid and cells
    vector<Cell*> grid_; // grid for all cells
    Cell* head_;
    char move_;

};
#endif // MAINWINDOW_H
