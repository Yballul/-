#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<Qpainter>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include"mybutton.h"
#include<QTimer>
#include<vector>
#include<QLabel>
#include<QString>
#include<QDebug>
#include"mybutton.h"
#include<QFont>
#include"coin.h"
#include"winscene.h"
#include<QVector>
#include"path.h"
#include"tips.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit PlayScene(QWidget *parent = nullptr);
   PlayScene(int index);
   int barindex;
   bool array[4][4];
   MyButton*btn_back;
   void paintEvent(QPaintEvent*);
   void backtochoose(QMainWindow*);
   coin*coinset[4][4];
   winscene*win;
   QVector<path*>helper;
   QVector<path*>answer;
   void Helpersendtips();
   tips*tip;
   QAction* tipsaction;
   QAction*god;
   bool ifadd;
   path*comparation;
   void godhand();



   bool ifwin;
   void send3();
signals:

};

#endif // PLAYSCENE_H
