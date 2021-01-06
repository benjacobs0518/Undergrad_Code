#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "cell.h"
#include "mainwindow.h"

Cell::Cell(bool alive, const int x, const int y) {
    alive_ = alive;
    x_ = x;
    y_ = y;

    x_adj = x_/width_; //adjust x coord
    y_adj = y_/width_; //adjust y coord

    if (alive_) {this->color_ = aliveColor_;} //if the cell is alive make color orange
    else{this->color_ = deadColor_;} //if the cell is dead make color white
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

//right and left click functionality on cells
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    //right click to kill cell
    if(event->button() == Qt::RightButton) {
        alive_ = false;
        color_ = deadColor_;
        qDebug() << "Killed cell at: " << this->x_adj << "," << this->y_adj;
    }

    //left click to bring to life
    else {
        alive_ = true;
        color_ = aliveColor_;
        qDebug() << "Added cell at: " << this->x_adj << "," << this->y_adj;
     }


    update(); //update changed values
}

void Cell::Step() {
    //if they became alive or died this is triggered, I used this instead of creating a new vector of cells to detect changed states
    if (condition_changed_) {
        alive_ = !alive_; //alter from dead to alive and vice versa
        if (alive_) {
            color_ = aliveColor_;
        } else {
            color_ = deadColor_;
        }
        update();
    }
    condition_changed_ = false; //change back to initial value
}

void Cell::set_neighbors(){
    int x = x_adj;
    int y = y_adj;

    //cell not located on neither on a corner nor a side
    if(x > 1 && y > 1 && x < 30 && y < 15){
        neighbors.push_back({x+1, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x-1, y-1}); //top left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x+1, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x-1, y+1}); //bottom left
     }

    //top left corner
    else if(x == 1 && y == 1){
        neighbors.push_back({x+1, y*15}); //top right
        neighbors.push_back({x, y*15}); //top
        neighbors.push_back({x*30, y*15}); //top left
        neighbors.push_back({x*30, y}); //left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x+1, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x*30, y+1}); //bottom left
     }

    //top right corner
    else if(x == 30 && y == 1){
        neighbors.push_back({x/30, y*15}); //top right
        neighbors.push_back({x, y*15}); //top
        neighbors.push_back({x-1, y*15}); //top left
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x/30, y}); //right
        neighbors.push_back({x/30, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x-1, y+1}); //bottom left
    }

    //bottom left corner
    else if(x == 1 && y == 15){
        neighbors.push_back({x+1, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x*30, y-1}); //top left
        neighbors.push_back({x*30, y}); //left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x+1, y/15}); //bottom right
        neighbors.push_back({x, y/15}); //bottom
        neighbors.push_back({x*30, y/15}); //bottom left
    }


    //bottom right corner
    else if(x == 30 && y == 15){
        neighbors.push_back({x/30, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x-1, y-1}); //top left
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x/30, y}); //right
        neighbors.push_back({x/30, y/15}); //bottom right
        neighbors.push_back({x, y/15}); //bottom
        neighbors.push_back({x-1, y/15}); //bottom left
    }

    //top center
    else if(y == 1){
        neighbors.push_back({x+1, y*15}); //top right
        neighbors.push_back({x, y*15}); //top
        neighbors.push_back({x-1, y*15}); //top left
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x+1, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x-1, y+1}); //bottom left
    }

    //bottom center
    else if(y == 15){
        neighbors.push_back({x+1, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x-1, y-1}); //top-left
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x+1, y/15}); //bottom right
        neighbors.push_back({x, y/15}); //bottom
        neighbors.push_back({x-1, y/15}); //bottom left
    }


    //cell is on the left side boundry
    else if(x == 1){
        neighbors.push_back({x+1, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x*30, y-1}); //top left
        neighbors.push_back({x*30, y}); //left
        neighbors.push_back({x+1, y}); //right
        neighbors.push_back({x+1, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x*30, y+1}); //bottom left
    }

    //cell is on the right side boundry
    else if(x == 30){
        neighbors.push_back({x/30, y-1}); //top right
        neighbors.push_back({x, y-1}); //top
        neighbors.push_back({x-1, y-1}); //top left
        neighbors.push_back({x-1, y}); //left
        neighbors.push_back({x/30, y}); //right
        neighbors.push_back({x/30, y+1}); //bottom right
        neighbors.push_back({x, y+1}); //bottom
        neighbors.push_back({x-1, y+1}); //bottom left
    }

}


