#include "gameController.h"
#include "snake.h"

Snake::Snake(GameController &controller) :
    controller(controller),
    head(0,0),
    moveDirection(None),
    grow(6),
    speed(6)
{
}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    foreach (QPointF cell, tail) {
        if(cell.x() >  maxX){
            maxX = cell.x();
        }
        if(cell.y() >  maxY){
            maxY = cell.y();
        }
        if(cell.x() <  minX){
            minX = cell.x();
        }
        if(cell.y() <  minY){
            minY = cell.y();
        }
    }

    QPointF topLeftPoint = mapFromScene(QPointF(minX, minY));
    QPointF bottomRightPoint = mapFromScene(QPointF(maxX, maxY));
    QRectF bound = QRectF(topLeftPoint.x(),topLeftPoint.y(),bottomRightPoint.x() - topLeftPoint.x() + CELL_SIZE, bottomRightPoint.y() - topLeftPoint.y() + CELL_SIZE);
    return bound;
}

QPainterPath Snake::shape() const
{
    QPainterPath body;
    body.setFillRule(Qt::WindingFill);

    body.addRect(QRectF(0, 0, CELL_SIZE, CELL_SIZE));

    foreach (QPointF p, tail) {
        QPointF itemp = mapFromScene(p);
        body.addRect(QRectF(itemp.x(), itemp.y(), CELL_SIZE, CELL_SIZE));
    }

    return body;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::green);
    //QRectF rec = QRect(198,220,21,21);
    painter->fillRect(QRect(0,0,22,22),QColor(0,125,18));
   // painter->drawRect(rec);
    painter->restore();
}


void Snake::setMoveDirection(Direction direction)
{
    if (moveDirection == Left && direction == Right)
        return;
    if (moveDirection == Right && direction == Left)
        return;
    if (moveDirection == Up && direction == Down)
        return;
    if (moveDirection == Down && direction == Up)
        return;
    moveDirection = direction;
}

Snake::Direction Snake::currentDirection()
{
	return moveDirection;
}

void Snake::advance(int step)
{
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        return;
    }
    if (moveDirection == None) {
        return;
    }

    if (grow > 0) {
		QPointF tailPoint = head;
        tail << tailPoint;
        grow -= 1;
    } else {
        tail.removeFirst();
        tail << head;
    }

    switch (moveDirection) {
        case None:
            break;
        case Left:
            moveLeft();
            break;
        case Right:
            moveRight();
            break;
        case Up:
            moveUp();
            break;
        case Down:
            moveDown();
            break;
    }

    setPos(head);
    handleCollisions();
}

void Snake::moveLeft()
{
    head.rx() -= CELL_SIZE;
    if (head.rx() < 0) {
        head.rx() = 660;
    }
}

void Snake::moveRight()
{
    head.rx() += CELL_SIZE;
    if (head.rx() >= 660) {
        head.rx() = 0;
    }
}

void Snake::moveUp()
{
    head.ry() -= CELL_SIZE;
    if (head.ry() < 0) {
        head.ry() = 440;
    }
}

void Snake::moveDown()
{
    head.ry() += CELL_SIZE;
    if (head.ry() >= 440) {
        head.ry() = 0;
    }
}

void Snake::handleCollisions()
{
    QList<QGraphicsItem *> collisions = collidingItems();

    // Check collisions with other objects on screen
    foreach (QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(Type) == Apple) {
            // Let GameController handle the event by putting another apple
            controller.snakeAteFood((Food *)collidingItem, Apple);
            grow += 2;
            controller.addScore(10);
        }
        else if (collidingItem->data(Type) == Rock) {
            controller.snakeAteFood((Food *)collidingItem, Rock);
            if(tail.length() > 8){
                for(int i=0;i<6;i++){
                    tail.pop_back();
                }
            }
            controller.addScore(-6);
            update();
        }
        else if (collidingItem->data(Type) == Power) {
            controller.snakeAteFood((Food *)collidingItem, Power);
            if(speed>3){
                speed = speed - 1;
            }
            controller.addScore(5);
        }
    }

    if (tail.contains(head)) {
        controller.snakeAteItself();
    }
}
