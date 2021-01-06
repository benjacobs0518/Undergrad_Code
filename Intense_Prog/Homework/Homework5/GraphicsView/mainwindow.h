#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *main_scene;
    QTimer m_timer;
};
#endif // MAINWINDOW_H
