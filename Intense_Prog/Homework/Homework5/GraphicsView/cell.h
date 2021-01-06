#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QGraphicsItem>
#include <QPropertyAnimation>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Cell: public QGraphicsObject
{
    Q_OBJECT
    //Q_PROPERTY()

public:
    Cell();
    Cell(const int x, const int y, bool s); //cell constructor
    static int get_width() {return width_;} //return width of each cell

    int get_x() const {return x_;} //get x coord
    int get_y() const {return y_;} //get y coord

    int get_xadj() const {return x_adj;} //get x adjusted to screen coord
    int get_yadj() const {return y_adj;} //get y adjusted to screen coord

    bool is_snake() {return snake_;}
    bool is_alive() {return alive_;}
    void kill() {alive_=false;}

    QRectF boundingRect() const override; //bounding rectangle
    QPainterPath shape() const override; //shape

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //paint override pre existing paintjob

    virtual void keyPressEvent(QKeyEvent *event);

    void move();

private:
    bool snake_;
    bool alive_;

    QString direction_;

    //size of cells
    static const int width_ = 22;

    //initial coordinates
    int x_;
    int y_;

    //adjusted coordinates
    int x_adj;
    int y_adj;

    //cell colors
    QColor color_;
    QColor body_ = QColor("red");
    QColor background_ = QColor("green");

};

#endif // CELL_H
