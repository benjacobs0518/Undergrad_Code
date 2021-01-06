#include <QPainter>

#include "gameWindow.h"
#include "food.h"

static const qreal FOOD_RADIUS = 5;

Food::Food(qreal x, qreal y, GameObjects z)
{
    setPos(x, y);
    setData(Type, z);
    if(z == Apple){
        c = Qt::red;
    }
    else if(z == Power){
        c = Qt::yellow;
    }
    else if(z == Rock){
        c = Qt::gray;
    }
}

QRectF Food::boundingRect() const
{
    return QRectF(0,0,CELL_SIZE,CELL_SIZE);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QPainterPath apple;
    apple.addEllipse(QPointF(CELL_SIZE / 2, CELL_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    painter->fillPath(apple, c);
    painter->restore();
}
