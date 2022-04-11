#include "playercar.h"
#include    "aicar.h"

PlayerCar::PlayerCar(QGraphicsPixmapItem *parent) :QObject(), QGraphicsPixmapItem(parent)
{
 //setPixmap(QPixmap(":/images/greencar.svg"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkcollison()));
    timer->start(10);


}

void PlayerCar::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up){
        //faster
          emit acceleratorPressed();
    }
    if(event->key()==Qt::Key_Down){
       emit breaksPressed();
    }
    if(event->key()==Qt::Key_Left){
        //left
        if(x()>=220){
            setPos(x()-20,y());
        }
    }
    if(event->key()==Qt::Key_Right){
        //right
        if(x()<=300){
      setPos(x()+20,y());
}
    }
}

void PlayerCar::checkcollison()
{
    QList<QGraphicsItem*>colid_items=collidingItems();

    for(int i=0;i<colid_items.size();i++){


        if(typeid (*(colid_items[i]))==typeid(AiCar)){
            //speed=0;
            //position=0;
         emit   carhasCrashed();


        }
    }
}
