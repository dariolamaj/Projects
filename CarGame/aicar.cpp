#include "aicar.h"

AiCar::AiCar(QGraphicsPixmapItem *parent) :QObject(), QGraphicsPixmapItem(parent)
{

}

AiCar::~AiCar()
{
    delete this;
}

void AiCar::moveup()
{

    if(x()<570){
       setPos(x()+6,y()-20);
       if(x()<569.99){
            setPos(x(),y()-20);
       }
    }
    else{
          setPos(x(),y()-20);
    }
    if(y()+50==0){
        scene()->removeItem(this);
        delete this;
    }
}
void AiCar::down()
{
    setPos(x(),y()+20);

    if(y()==602){
        scene()->removeItem(this);
        delete this;
    }
}
