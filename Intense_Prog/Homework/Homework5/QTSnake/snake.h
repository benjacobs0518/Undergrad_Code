#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QRectF>

#include "gameWindow.h"

class GameController;

class Snake : public QGraphicsItem
{
public:
    enum Direction {None,Left,Right,Up,Down};

    Snake(GameController & controller);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void setMoveDirection(Direction direction);
	Direction currentDirection();

protected:
    void advance(int step);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void handleCollisions();

    GameController &controller;
    QPointF head;
    QList<QPointF> tail;
    Direction moveDirection;
    int grow;
    int speed;
    int tickCounter;
};

#endif // SNAKE_H
