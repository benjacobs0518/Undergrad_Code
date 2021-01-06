#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *app, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_pressed();

    void on_startButton_pressed();

    void on_playerName_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QApplication *app;
    QString m_username;

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
