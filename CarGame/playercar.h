#ifndef PLAYERCAR_H
#define PLAYERCAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QWidget>
class PlayerCar : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit PlayerCar(QGraphicsPixmapItem *parent = nullptr);
     void keyPressEvent(QKeyEvent * event);


signals:
     void breaksPressed();
     void acceleratorPressed();
     void carhasCrashed();
public slots:
     void checkcollison();
};

#endif // PLAYERCAR_H
