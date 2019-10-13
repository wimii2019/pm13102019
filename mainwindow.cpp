#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWidget = new Widget(this);
    setCentralWidget(myWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
