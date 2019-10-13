#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWidget = new Widget(this);
    setCentralWidget(myWidget);
    coord  = new QLabel("test",this);
    ui->statusbar->addPermanentWidget(coord);
    connect(myWidget,SIGNAL(changeMousePosition(int, int)),this,SLOT(mousePos()));

    colorButton = new QToolButton(this);
    ui->toolBar->addWidget(colorButton);
    //connect(clicked(),)

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

void MainWindow::on_actionLoad_triggered()
{
    myWidget->load(QFileDialog().getOpenFileName(this,"Open file"));
    ui->statusbar->showMessage("File loaded",5000 );
}

void MainWindow::on_actionSave_triggered()
{
    myWidget->save(QFileDialog().getSaveFileName());
}

void MainWindow::on_actionNew_triggered()
{
    myWidget->newPicture();
}

void MainWindow::mousePos(int x, int y)
{
        coord->setText(QString(x)+" " +QString(y));
}
