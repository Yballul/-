#ifndef WINSCENE_H
#define WINSCENE_H

#include <QMainWindow>
#include<QPainter>
#include<QPaintDevice>
#include<QPixmap>
#include<QMenu>
#include<QMenuBar>
#include<QLabel>
#include"mybutton.h"
#include<QACtion>
#include<QFont>

class winscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit winscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*e);
    void backtomainscene(QMainWindow*);
    MyButton*btn_back;

signals:

};

#endif // WINSCENE_H
