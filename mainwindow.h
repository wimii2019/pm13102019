#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Widget *myWidget;
};

#endif // MAINWINDOW_H
