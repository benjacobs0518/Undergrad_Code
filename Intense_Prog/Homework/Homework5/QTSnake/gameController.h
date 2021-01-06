#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gameWindow.h"

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;

enum GameObjects {Type,Apple,Power,Rock};

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0);
    ~GameController();

    void snakeAteFood(Food *food, GameObjects z);
    void snakeAteItself();
    void addScore(int x) { score = score + x;}

public slots:
    void gameOver();

protected:
     bool eventFilter(QObject *object, QEvent *event);

private:
    QGraphicsScene &scene;
    Snake *snake;
    bool secondTurn;
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood(GameObjects z);
    QTimer timer;

    int score;
};

#endif // GAMECONTROLLER_H
