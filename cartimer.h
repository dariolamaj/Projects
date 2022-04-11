#ifndef CARTIMER_H
#define CARTIMER_H

#include <QObject>

class CarTimer : public QObject
{
    Q_OBJECT
public:
    explicit CarTimer(QObject *parent = nullptr);

signals:

};

#endif // CARTIMER_H
