#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include<QVector>
#include<QPixmap>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Draw();


private slots:
    void on_selectbtn_clicked();

    void on_rightbtn_clicked();

    void on_leftbtn_clicked();

    void on_startgamebtn_clicked();

    void on_newgamebtn_clicked();

    void on_settingbtn_clicked();

    void on_quitntn_clicked();

    void on_pushButton_clicked();
    void carcrashedsignal();

private:
    Ui::MainWindow *ui;
    Game *game=nullptr;
    QVector<QPixmap>CarsList;
    int cardisplayindex=0;
};
#endif // MAINWINDOW_H
