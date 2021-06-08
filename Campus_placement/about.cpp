#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

void About::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen myPen(Qt::blue);
    myPen.setWidth(2);
    myPen.setStyle(Qt::DashDotDotLine);
    painter.setPen(myPen);

    QPoint a;
    a.setX(0);
    a.setY(0);

    QPoint a1;
    a1.setX(300);
    a1.setY(0);

    QPoint b;
    b.setX(0);
    b.setY(300);

    QPoint b1;
    b1.setX(300);
    b1.setY(300);

    painter.drawLine(a, a1);
    painter.drawLine(a, b1);
    painter.drawLine(b, b1);
    painter.drawLine(b, a1);

    QPoint o;
    o.setX(150);
    o.setY(150);

    myPen.setWidth(5);
    painter.setBrush(QBrush(Qt::red));
    myPen.setColor(Qt::yellow);
    myPen.setStyle(Qt::SolidLine);
    painter.setPen(myPen);
    painter.drawEllipse(o,30,30);

    QPoint p1;
    p1.setX(45);
    p1.setY(75);

    QPoint p2;
    p2.setX(255);
    p2.setY(75);

    QPoint p3;
    p3.setX(45);
    p3.setY(225);

    QPoint p4;
    p4.setX(255);
    p4.setY(225);

    myPen.setWidth(2);
    myPen.setColor(Qt::black);
    painter.setPen(myPen);
    painter.drawLine(p1,p2);
    painter.drawLine(p3,p4);
    painter.drawLine(p2,p4);
    painter.drawLine(p1,p3);

    QPoint m1;
    m1.setX(45);
    m1.setY(150);

    QPoint m2;
    m2.setX(255);
    m2.setY(150);

    QPoint u1;
    u1.setX(0);
    u1.setY(90);

    QPoint u2;
    u2.setX(0);
    u2.setY(195);

    QPoint u3;
    u3.setX(300);
    u3.setY(90);

    QPoint u4;
    u4.setX(300);
    u4.setY(195);

    myPen.setWidth(3);
    myPen.setColor(Qt::darkMagenta);
    myPen.setStyle(Qt::DotLine);
    painter.setPen(myPen);
    painter.drawLine(m1,u1);
    painter.drawLine(m1,u2);
    painter.drawLine(m2,u3);
    painter.drawLine(m2,u4);
}

About::~About()
{
    delete ui;
}
