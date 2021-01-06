#ifndef HEAD_H
#define HEAD_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QThread>

class Head : public QGraphicsItem
{
public:
    Head();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);


protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void DoCollision();
    QString direction_;
    QList<QPointF> tail;

    QPointF        head;

};

#endif // HEAD_H
