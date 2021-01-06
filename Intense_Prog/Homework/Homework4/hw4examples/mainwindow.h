#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shape.h"
#include <QMainWindow>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_timer_fired();

private:
    Ui::MainWindow *ui;

    QGraphicsView * view;

    int time_steps_;

    std::vector<ShapeObj *> points_;
};
#endif // MAINWINDOW_H
