#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QGraphicsItem>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Cell: public QGraphicsObject
{
    Q_OBJECT

public:
    Cell();
    bool condition_changed_; //if they become alive or die change this value

    Cell(const int x, const int y); //cell constructor
    static int get_width() {return width_;} //return width of each cell

    int get_x() const {return x_;} //get x coord
    int get_y() const {return y_;} //get y coord

    int get_xadj() const {return x_adj;} //get x adjusted to screen coord
    int get_yadj() const {return y_adj;} //get y adjusted to screen coord

    void setBody();

    QRectF boundingRect() const override; //bounding rectangle
    QPainterPath shape() const override; //shape

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //paint override pre existing paintjob

    void Step(char m); //checks if the cell has changed from living/dead

    void set_neighbors(); //set neigboring values
    vector< tuple<int, int> > get_neighbors() {return neighbors;} //get neigbor coord vector


private:
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
    QColor background_ = QColor(121,89,0);
    QColor body_ = QColor("green");

    vector< tuple<int, int> > neighbors; //vector of surrounding neighbor coordinates
};

#endif // CELL_H
