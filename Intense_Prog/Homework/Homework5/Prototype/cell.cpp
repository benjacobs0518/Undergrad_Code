#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QKeyEvent>

#include "cell.h"
#include "mainwindow.h"

Cell::Cell(const int x, const int y) {
    x_ = x;
    y_ = y;

    x_adj = x_/width_; //adjust x coord
    y_adj = y_/width_; //adjust y coord

    this->color_ = background_; //if the cell is alive make color orange
}

void Cell::setBody(){
    color_ = body_;
}

QRectF Cell::boundingRect() const {
    return QRectF(x_, y_, width_, width_); //return the bounding rect
}

QPainterPath Cell::shape() const {
    QPainterPath area;
    area.addRect(x_, y_, width_, width_); //shape of rectangle in area
    return area;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option); //handle unused param
    Q_UNUSED(widget);//handle handle param

    painter->setBrush(QBrush(color_)); //white or orange depending on state
    painter->setPen(Qt::black); //grid black
    painter->drawRect(this->x_, this->y_, this->width_, this->width_); //draw cell
}


void Cell::Step(char m) {
    if(m == 'W'){
        y_ = y_ - width_;
        //x_ = x_ - width_;
        qDebug("pressed");
    }
    else if(m == 'A'){
        //y_ = y_ - width_;
        x_ = x_ - width_;
        qDebug("pressed");
    }
    else if(m == 'S'){
        y_ = y_ + width_;
        //x_ = x_ - width_;
        qDebug("pressed");
    }
    else if(m == 'D'){
        //y_ = y_ - width_;
        x_ = x_ + width_;
        qDebug("pressed");
    }

    update();
}


