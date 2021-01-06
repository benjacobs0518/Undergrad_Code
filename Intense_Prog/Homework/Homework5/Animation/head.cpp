#include "head.h"

Head::Head()
{
    //random start rotation
    //angle = (qrand() % 360);
    //setRotation(angle);

    //set the speed
    speed = 22;

    //random start position
    int StartX = -100;
    int StartY = 50;

    /*
    if((qrand() % 1))
    {
        StartX = (qrand() %200);
        StartY = (qrand() %200);
    }
    else
    {
        StartX = (qrand() % -100);
        StartY = (qrand() % -100);
    }
    */

    setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(mapToParent(StartX,StartY));

}

QRectF Head::boundingRect() const
{
    return QRect(0,0,22,22);

}

void Head::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::white);

    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
        Brush.setColor(Qt::green);
    }
    else
    {
        //collision
        Brush.setColor(Qt::red);

        //Set the position
        DoCollision();
    }

    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}


void Head::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();


    if(this->direction_ == "right"){
        setPos(mapToParent(speed,0));
    }
    else if(this->direction_ == "left")
    {
         setPos(mapToParent(-speed,0));
    }
    else if(this->direction_ == "up")
    {
         setPos(mapToParent(0,-speed));
    }
    else if(this->direction_ == "down")
    {
         setPos(mapToParent(0,22));
    }


}

void Head::DoCollision()
{
    this->speed = 0;
}

void Head::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Right: {
            this->direction_ = "right";
            qDebug("right");
            break;
        }
        case Qt::Key_Left: {
            this->direction_ = "left";
            qDebug("left");
            break;
        }
        case Qt::Key_Up: {
            this->direction_ = "up";
            qDebug("up");
            break;
        }
        case Qt::Key_Down: {
            this->direction_ = "down";
            qDebug("down");
            break;
        }
    }

    update();
}


