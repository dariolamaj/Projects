#include "scores.h"
#include<QFont>
Scores::Scores(QGraphicsTextItem *parent):QGraphicsTextItem(parent)
{
    score=0;
setPlainText(QString("Scores: ")+QString::number(score));
setDefaultTextColor(Qt::blue);
setFont(QFont("times",17));

QTimer *timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(increasescore()));
timer->start(10000);

}

int Scores::GetScores()
{
    return this->score;
}

void Scores::increasescore()
{
    score++;
    setPlainText(QString("Scores: ")+QString::number(score));
    if(score==100){
        emit gameend();
    }
}
