#ifndef FOOD_H
#define FOOD_H

#include "gameWindow.h"

class Food : public QGraphicsItem
{
public:
    Food(qreal x, qreal y, GameObjects z);
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
    QColor c;
    GameObjects z;
};

#endif // FOOD_H
