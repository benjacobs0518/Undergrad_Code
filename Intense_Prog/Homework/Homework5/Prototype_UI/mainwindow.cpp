#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    if(ui->playerName->text().isEmpty())
        ui->warningLabel->setText("Set player name...");
    else
    {
        ui->warningLabel->setText("");
        m_username = ui->playerName->text();
    }

}

void MainWindow::on_playerName_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
        ui->warningLabel->setText("Set player name...");
    else
        ui->warningLabel->setText("");
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton exit =
            QMessageBox::question( this, "Snake 3D",
tr("Do you really want to quit game?\n"),
QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes);

       if (exit != QMessageBox::Yes) {
           event->ignore();
       } else {
           event->accept();
       }
}
