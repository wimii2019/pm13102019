#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"

#include <QMainWindow>
#include <QLabel>
#include <QToolButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPen_triggered();

    void on_actionLine_triggered();

    void on_actionRectl_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionNew_triggered();

public slots:
    void mousePos(int x, int y);

private:
    Ui::MainWindow *ui;
    Widget *myWidget;
    QLabel *coord;
    QToolBar *toolBar;
    QToolButton *colorButton;
};

#endif // MAINWINDOW_H
