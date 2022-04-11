#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "game.h"
#include <QObject>

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
private slots:
    void carcrashedsignal();
    void startgame();
signals:
private:

};

#endif // CONTROLLER_H
