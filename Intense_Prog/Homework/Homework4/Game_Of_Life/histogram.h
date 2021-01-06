
#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QGraphicsItem>

class Histogram: public QGraphicsObject
{
    Q_OBJECT
public:

    Histogram(const int x, const int y, int h); //constructor
    static int get_width() {return width_;} //return width of each histogram
    int get_x() {return x_;} // return x coord
    void set_x(int offset) {x_ = x_ + offset;} //set x by the appropriate offset value

    QRectF boundingRect() const override; //bounding rect
    QPainterPath shape() const override; //shape

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;  //paint override pre existing paintjob

private:
    //histogram coordinates
    int x_;
    int y_;

    //histogram color
    QColor color_;

    //width of each histogram
    static const int width_ = 30;

    //height of histogram
    int height_;
};

#endif // HISTOGRAM_H
