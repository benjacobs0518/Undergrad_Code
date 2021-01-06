#include "mainMenu.h"
#include "ui_mainMenu.h"
#include <QDebug>

MainWindow::MainWindow(QApplication *app, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->app = app;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_pressed()
{
    app->quit();
}

void MainWindow::on_startButton_pressed()
{
    if(ui->playerName1->text().isEmpty())
        ui->warningLabel->setText("Please enter player 1's name");
    else
    {
        ui->warningLabel->setText("");
        m_username1 = ui->playerName1->text();
        qDebug("player ones name is:");
        qDebug(m_username1.toLatin1());
        g_.setName(ui->playerName1->text());
        if(!ui->playerName2->text().isEmpty())
        {
          m_username2 = ui->playerName2->text();
          qDebug("player twos name is:");
          qDebug(m_username2.toLatin1());
        }
        this->hide();
        g_.show();
        g_.update();
    }
}

void MainWindow::on_playerName_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
        ui->warningLabel->setText("Please enter player 1's name");
    else
        ui->warningLabel->setText("");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton exit = QMessageBox::question(this, "Ben Jacobs Snake",
                          tr("Are you sure you want to quit?"),
                             QMessageBox::Yes | QMessageBox::No);

    if(exit == QMessageBox::No)
        event->ignore();
    else
        event->accept();

}

void MainWindow::on_rulesButton_clicked()
{

}
