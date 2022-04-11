#ifndef AICAR_H
#define AICAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include<random>
class AiCar : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit AiCar(QGraphicsPixmapItem *parent = nullptr);
    ~AiCar();

signals:
public slots:
    void moveup();
    void down();
private:


};

#endif // AICAR_H
