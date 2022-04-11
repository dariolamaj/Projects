#include "game.h"
#include<QDebug>
Game::Game(QWidget *parent):QGraphicsView(parent)
{
  scene=new  QGraphicsScene(parent);

}

void Game::setcarindex(int index)
{
    cardisplayindex=index;
}

void Game::startgame()
{
    initializeList();
    autoCar=new AiCar();
    player=new PlayerCar();
    road=new Road();

    road->setPixmap(QPixmap(":/images/Road.jpg"));

    scores=new Scores();
    time=new MyTimer();
    player->setPixmap(CarsList.at(cardisplayindex));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(road);
    scene->addItem(scores);
    scene->addItem(time);
    scene->addItem(player);
    scene->addItem(autoCar);
    view=new QGraphicsView();
    scene->setBackgroundBrush(QBrush(Qt::green));
    view->setScene(scene);
    view->show();
    view->setFixedSize(nWidth,nHeight);
    scene->setSceneRect(0,100,nWidth,nHeight);
    road->setPos((view->width()/2-60),0);
    scores->setPos(5,100);
    time->setPos(5,125);

    player->setPos((view->width()/2-150)+200,(rand()%view->height()/2+view->height()/3)-10);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 connect(player, SIGNAL(acceleratorPressed()), road, SLOT(acceleratorPressed()));
 connect(player, SIGNAL(breaksPressed()), road, SLOT(breaksPressed()));
 Carreleasetimer = new QTimer(this);
 connect(Carreleasetimer, SIGNAL(timeout()), this, SLOT(createAcar()));
 connect(player, SIGNAL(carhasCrashed()), this, SLOT(carcrashed()));
 connect(scores, SIGNAL(gameend()), this, SLOT(gameendslotView()));

 Carreleasetimer->start(carRelease);
}
void Game::initializeList()
{
    //up cars initialization
    CarsList.append(QPixmap(":/images/greencar.svg"));
    CarsList.append(QPixmap(":/images/yellowcar.svg"));
    CarsList.append(QPixmap(":/images/greencar.svg"));
    CarsList.append(QPixmap(":/images/greencar.svg"));
    //down car list
    dCarsList.append(QPixmap(":/images/dgreencar.svg"));
    dCarsList.append(QPixmap(":/images/dyellowcar.svg"));
    dCarsList.append(QPixmap(":/images/dgreencar.svg"));
    dCarsList.append(QPixmap(":/images/dgreencar.svg"));
}
void Game::createAcar()
{
    carRelease=(rand()%10+5)*1000;
    Carreleasetimer->start(carRelease);
    carMovementRad=rand()%2+1;

    if(carMovementRad==1){
        CarMovingUp();
    }
    if(carMovementRad==2){
        CarMovingDowns();
    }
}

void Game::carcrashed()
{
    emit carcrashedsignal();
    view->hide();

    delete view;
    delete this;
}

void Game::gameendslot()
{


    emit carcrashedsignal();
    view->hide();
}

void Game::gameendslotView()
{
    scene->addItem(gameend);
     QTimer::singleShot(200, this, SLOT(gameendslot()));
}
void Game::CarMovingUp()
{
    AiCar *car=new AiCar();
    car->setPixmap(CarsList.at(rand()%3+0));
    scene->addItem(car);
    car->setPos(scene->width()/2-45,600);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), car, SLOT(moveup()));
    timer->start(100);
}
void Game::CarMovingDowns()
{
    AiCar *car=new AiCar();
    car->setPixmap(dCarsList.at(rand()%3+0));
    scene->addItem(car);
    car->setPos(scene->width()/2-45,0);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), car, SLOT(down()));
    timer->start(100);
}
