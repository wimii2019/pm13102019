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

void MainWindow::on_actionPen_triggered()
{
   myWidget->mode='r';
}

void MainWindow::on_actionLine_triggered()
{
    myWidget->mode='l';
}

void MainWindow::on_actionRectl_triggered()
{
    myWidget->mode='p';
}
