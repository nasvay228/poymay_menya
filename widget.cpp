#include "widget.h"
#include "ui_widget.h"
#include <cmath>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(changeCoords()));
    timer.start(2000);
}

Widget::~Widget()
{
    delete ui;

}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (r*r>(ball_x - e->x())*(ball_x - e->x())+(ball_y - e->y())*(ball_y - e->y()))
    {
        ui->lcdNumber->display(schet);
        schet += 1;
    }

}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();
    r = 50;
    painter.setPen(Qt::red);
    painter.drawRect(0,0,width-1,height-1);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(QPoint(ball_x,ball_y),r,r);
}

bool Widget::checkCoords(int x, int y)
{
    if (ball_x == x and ball_y == y){
        return true;
    }
    else{
        return false;
    }
    
    
}
void Widget::changeCoords()
{
    ball_x = rand()%width();
    ball_y = rand()%height();
    qDebug()<<ball_x <<" "<< ball_y << '\n';
    repaint();
}
