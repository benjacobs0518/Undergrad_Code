#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QKeyEvent>
#include "cell.h"

Cell::Cell(const int x, const int y, bool s) {
    x_ = x;
    y_ = y;
    snake_=s;

    x_adj = x_/width_; //adjust x coord
    y_adj = y_/width_; //adjust y coord

    if(snake_){
       this->color_ = body_; //if the cell is alive make color orange
       this->alive_ = true;
    }
    else{
        this->color_ = background_; //if the cell is alive make color orange
        this->alive_ = false;
    }
    setFlag(QGraphicsItem::ItemIsFocusable);
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

void Cell::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Right: {
            this->direction_ = "right";
            break;
        }
        case Qt::Key_Left: {
            this->direction_ = "left";
            break;
        }
        case Qt::Key_Up: {
            this->direction_ = "up";
            break;
        }
        case Qt::Key_Down: {
            this->direction_ = "down";
            break;
        }
    }
    move();
}

void Cell::move(){

    if(this->direction_ == "right"){
        moveBy(22,0);
    }
    else if(this->direction_ == "left")
    {
         moveBy(-22,0);
    }
    else if(this->direction_ == "up")
    {
         moveBy(0,-22);
    }
    else if(this->direction_ == "down")
    {
         moveBy(0,22);
    }

    update();

}



