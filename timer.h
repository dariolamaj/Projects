#ifndef MyTimer_H
#define MyTimer_H
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include<QObject>
#include<QTimer>

class MyTimer:public QGraphicsTextItem
{
Q_OBJECT
public:
    MyTimer(QGraphicsTextItem *parent=nullptr);

public slots:
    void increaseMyTimer();

private:
    int Time=0;
};

#endif // MyTimer_H
