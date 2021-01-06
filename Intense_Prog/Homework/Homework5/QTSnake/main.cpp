#include "mainMenu.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&a);
    w.show();

    QFile file(":/Styling/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    a.setStyleSheet(stylesheet);

    return a.exec();
}
