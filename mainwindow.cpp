#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QGraphicsItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
         ui->setupUi(this);
         CarsList.append(QPixmap(":/images/greencar.svg"));
         CarsList.append(QPixmap(":/images/yellowcar.svg"));
         CarsList.append(QPixmap(":/images/greencar.svg"));
         CarsList.append(QPixmap(":/images/greencar.svg"));
         ui->cardisplay->setPixmap(CarsList.at(0));
         game=new Game();

         connect(game, SIGNAL(carcrashedsignal()), this, SLOT(carcrashedsignal()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_selectbtn_clicked()
{
this->game->setcarindex(cardisplayindex);
this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_rightbtn_clicked()
{
    if(cardisplayindex<3){
        cardisplayindex++;
        ui->cardisplay->setPixmap(CarsList.at(cardisplayindex));
    }
}

void MainWindow::on_leftbtn_clicked()
{
    if(cardisplayindex>0){
        cardisplayindex--;
        ui->cardisplay->setPixmap(CarsList.at(cardisplayindex));
    }

}

void MainWindow::on_startgamebtn_clicked()
{

game->startgame();
this->close();
}

void MainWindow::on_newgamebtn_clicked()
{
this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_settingbtn_clicked()
{
this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_quitntn_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::carcrashedsignal()
{

    this->show();

}
