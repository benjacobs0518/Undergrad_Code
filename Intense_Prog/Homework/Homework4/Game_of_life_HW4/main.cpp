#include "main.h"
#include "ui_main.h"

main::main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Hello World!");
}

main::~main()
{
    delete ui;
}

