#ifndef ROAD_H
#define ROAD_H
#include <QGraphicsScene>
#include <QWidget>
#include<QTimer>
#include<QObject>
#include<QList>
#include<QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "aicar.h"
#include "playercar.h"
class Road : public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    explicit Road(QGraphicsItem *parent = nullptr);
int getSpeed();
signals:
public slots:
    void MoveRoad();
    void acceleratorPressed();
    void breaksPressed();

private:
int position=0;
int speed=1;

};

#endif // ROAD_H
