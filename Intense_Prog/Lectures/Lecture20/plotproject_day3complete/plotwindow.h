#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "point.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();


private slots:
    // default slot that reacts to random button being clicked
    void on_randomButton_clicked();

    // Day 2, Task 2, option 1 (default slot)
//    void on_addButton_clicked();
    // Day 2, Task 2, option 2 (custom slot)
    void AddPoint();


    // Day 1, Task 5
    // custom slot that we have to connect to a signal
    void SlotTest();

    // Day 2, Task 3
    // the parameters match the parameters of the signal
    // Day 3, Task 1 - change to Point * p parameter
    void PointSelectedSlot(Point * p);

    // Day 3, Task 3
    void DeletePointSlot(Point * p);

    // Day 3, Task 2
    void on_deletePoints_clicked();

private:
    void AddHelper();


    Ui::PlotWindow *ui;

    QGraphicsScene *scene;

    Point * first_point_;

    // Day 3, Task 2
    // okay if static, but you'll need to use a different architecture
    bool delete_mode_;
};

#endif // PLOTWINDOW_H
