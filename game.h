#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QWidget>
#include<QObject>
#include<QVector>
#include<QPixmap>

#include "playercar.h"
#include "road.h"
#include "scores.h"
#include "timer.h"
#include "aicar.h"
#include"gameend.h"

class Game:public QGraphicsView
{
Q_OBJECT
public:
    Game(QWidget *parent=nullptr);
    void setcarindex(int index);
    void startgame();
private:
    AiCar *autoCar=nullptr;
    PlayerCar *player=nullptr;
    Road *road=nullptr;
    Scores *scores=nullptr;
    GameEnd *gameend=nullptr;
    MyTimer *time=nullptr;
    QGraphicsScene *scene=nullptr;
    QGraphicsView *view=nullptr;
    int nHeight=600;
    int nWidth=500;
    QVector<QPixmap>dCarsList;
    QVector<QPixmap>CarsList;

    void initializeList();

    //--------------------------car
    QTimer *Carreleasetimer=nullptr;
    int carMovementRad=1;
    int carRelease=1000;
    void CarMovingUp();
    void CarMovingDowns();
    int cardisplayindex=0;
 signals:
    void carcrashedsignal();

public slots:
void createAcar();
void carcrashed();
void gameendslot();
void gameendslotView();
};

#endif // GAME_H
