#include "widget.h"
#include "ui_widget.h"
#include "QMouseEvent"

#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::Widget),
    image(800,600,QImage::Format_ARGB32),
    tempImage(800,600,QImage::Format_ARGB32),
    mode('r')
{
    ui->setupUi(this);
    image.fill(Qt::white);
    tempImage.fill(Qt::white);

    QPainter p(&image);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newPicture()
{
    image.fill(Qt::white);
    tempImage = image;
    repaint();
}

void Widget::load(QString fileName)
{
    image.load(fileName);
    tempImage = image;
    repaint();
}

void Widget::save(QString fileName)
{
    image.save(fileName);
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawImage(0,0,tempImage);

}

void Widget::mouseMoveEvent(QMouseEvent *e){
    if(mode == 'r'){
        QPainter p(&tempImage);
        p.drawLine(x0,y0,e->x(),e->y());
        x0 = e->x();
        y0 = e->y();
        image=tempImage;
    }
    if(mode =='l'){
       tempImage =image;
       QPainter p(&tempImage);
       p.drawLine(x0,y0,e->x(),e->y());
    }
    if(mode == 'p'){
        tempImage =image;
        QPainter p(&tempImage);
        QRect a(QPoint(x0,y0),QPoint(e->x(),e->y()));
        p.drawRect(a);
    }
    repaint();
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    x0 = e->x();
    y0 = e->y();
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_L)
        mode = 'l';
    if(e->key()==Qt::Key_R)
        mode = 'r';
    if(e->key()==Qt::Key_P)
        mode = 'p';
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    QPainter p(&image);
    if(mode == 'l'){
        p.drawLine(x0,y0,e->x(),e->y());
    }
    if(mode == 'p'){
        QRect a(QPoint(x0,y0),QPoint(e->x(),e->y()));
        p.drawRect(a);
    }
    repaint();
}
