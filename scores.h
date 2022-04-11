#ifndef SCORES_H
#define SCORES_H
#include <QGraphicsTextItem>
#include<QTimer>
#include<QGraphicsScene>
class Scores:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Scores(QGraphicsTextItem *parent=nullptr);
    int GetScores();

public slots:

    void increasescore();
signals:
    void gameend();
private:
    int score=0;
};

#endif // SCORES_H
