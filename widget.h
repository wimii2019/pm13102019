#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    char mode;
    QColor color;

    void newPicture();
    void load(QString fileName);
    void save(QString fileName);


protected:
    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:
    void changeMousePosition(int x, int y);

private:
    Ui::Widget *ui;
    QImage image;
    QImage tempImage;
    int x0;
    int y0;

};;

#endif // WIDGET_H
