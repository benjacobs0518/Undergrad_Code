#ifndef DIALOG_H
#define DIALOG_H

#include "head.h"

#include <QMainWindow>
#include <QDialog>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    int length;
    QVector<Head> body;
};
#endif // DIALOG_H
