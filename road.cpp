#include "road.h"
#include<QDebug>
Road::Road(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveRoad()));
    timer->start(10);
}

int Road::getSpeed()
{
    return speed;
}

void Road::MoveRoad()
{
position+=speed;
setY(position);
if (this->y() >50) {
    setY(0);
position=0;
}

}

void Road::acceleratorPressed()
{
   if(speed<40)
    speed+=1;
}

void Road::breaksPressed()
{
if(position>=0){
    if(speed>0)
    speed-=1;
}
}


