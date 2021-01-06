#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include "gameWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication *app, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_pressed();

    void on_startButton_pressed();

    void on_playerName_textChanged(const QString &arg1);

    void on_rulesButton_clicked();

private:
    Ui::MainWindow *ui;
    QApplication *app;
    QString m_username1;
    QString m_username2;
    GameWindow g_;
    //Rules r_;

    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
