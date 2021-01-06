#include "gameController.h"
#include "food.h"
#include "snake.h"
#include "gameWindow.h"

GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    snake(new Snake(*this))
{
    timer.start(15);
    score = 0;

    scene.addItem(snake);
    scene.installEventFilter(this);

    Food *apple = new Food(286, 176, Apple);
    scene.addItem(apple);

    Food *spike = new Food(528, 330, Rock);
    scene.addItem(spike);

    Food *power = new Food(374, 308, Power);
    scene.addItem(power);

    connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
}

GameController::~GameController()
{
}

void GameController::snakeAteFood(Food *food, GameObjects z)
{
    scene.removeItem(food);
    addNewFood(z);
}

void GameController::snakeAteItself()
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            snake->setMoveDirection(Snake::Left);
            break;
        case Qt::Key_Right:
            snake->setMoveDirection(Snake::Right);
            break;
        case Qt::Key_Up:
            snake->setMoveDirection(Snake::Up);
            break;
        case Qt::Key_Down:
            snake->setMoveDirection(Snake::Down);
            break;
    }
}

void GameController::addNewFood(GameObjects z)
{
    int x = (int)(qrand() % 30);
    int y = (int)(qrand() % 20);
    x *= CELL_SIZE;
    y *= CELL_SIZE;

    while (snake->shape().contains(snake->mapFromScene(QPointF(x + 11, y + 11))))
    {
        x = (int)(qrand() % 30);
        y = (int)(qrand() % 20);

        x *= CELL_SIZE;
        y *= CELL_SIZE;
    }

    Food *food = new Food(x, y, z);
    scene.addItem(food);
}

void GameController::gameOver()
{
    disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));

    if(secondTurn == false){
        if (QMessageBox::Yes == QMessageBox::information(NULL,
                                tr("Player 1 Game Over"), tr("Player 2 are you ready?"),
                                QMessageBox::Yes | QMessageBox::No,
                                QMessageBox::Yes)) {
            secondTurn = true;
            connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
            scene.clear();
            snake = new Snake(*this);
            scene.addItem(snake);
            addNewFood(Apple);
            addNewFood(Rock);
            addNewFood(Power);
            qDebug()<<"Player 1, you had a total score of: "<< score;
            score = 0;

        }
        else {
            qDebug()<<"Player 1, you had a total score of: "<< score;
            exit(0);
        }
    }

    else{
        if (QMessageBox::Yes == QMessageBox::information(NULL,
                                tr("Player 2 Game Over"), tr("Do you two wish to play again?"),
                                QMessageBox::Yes | QMessageBox::No,
                                QMessageBox::Yes)) {
            connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
            scene.clear();
            snake = new Snake(*this);
            scene.addItem(snake);
            addNewFood(Apple);
            addNewFood(Rock);
            addNewFood(Power);
            qDebug()<<"Player 2, you had a total score of: "<< score;
            score = 0;
            secondTurn = false;
        }
        else {
            qDebug()<<"Player 2, you had a total score of: "<< score;
            exit(0);
        }
    }
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
