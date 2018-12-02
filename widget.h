#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
    

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int ball_y;
    int ball_x;
    int schet;
    int x;
    int y;
    int r;

private:
    Ui::Widget *ui;
    QTimer timer;    
protected:
    void mousePressEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent * e);

protected slots:
    void changeCoords();
    bool checkCoords(int x, int y);

};

#endif // WIDGET_H
