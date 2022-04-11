#include "controller.h"

controller::controller(QObject *parent) : QObject(parent)
{
//connect(game, SIGNAL(carcrashedsignal()), this, SLOT(carcrashedsignal()));



    //connect(menu, SIGNAL(startgame()), this, SLOT(startgame()));
}

void controller::carcrashedsignal()
{

}

void controller::startgame()
{

   Game *game=new Game();
   game->startgame();
}
