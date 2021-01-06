#include <iostream>
#include <QtWidgets>

#include "histogram.h"
#include "mainwindow.h"

Histogram::Histogram(const int x, const int y, int h)
{
    //assigning values to cell
    x_ = x;
    y_ = y;
    height_ = -h;
    color_ = "white";
}


QRectF Histogram::boundingRect() const {
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Histogram::shape() const {
    QPainterPath area;
    area.addRect(x_, y_, width_, height_);
    return area;
}

//Histogram paint
void Histogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option); //handle unused param
    Q_UNUSED(widget); //handle unused param
    painter->setBrush(QBrush("white")); //make histogram white
    painter->setPen(Qt::black); //ouline in black
    painter->drawRect(this->x_, this->y_, this->width_, this->height_); //draw histogram
}
