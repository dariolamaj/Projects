#include "timer.h"
#include<QFont>


MyTimer::MyTimer(QGraphicsTextItem *parent):QGraphicsTextItem(parent)
{
    Time=0;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(increaseMyTimer()));
    timer->start(1000);

    setPlainText(QString("Time: ")+QString::number(Time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",17));
}

void MyTimer::increaseMyTimer()
{
     Time++;
     setPlainText(QString("Time: ")+QString::number(Time));
}
