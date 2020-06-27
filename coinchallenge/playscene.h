#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include<QFile>
#include<QMainWindow>
#include<QPainter>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QTimer>
#include<QLabel>
#include<QString>
#include<QDebug>
#include<QVector>
#include"path.h"
#include"tips.h"
#include<QFont>
#include"coin.h"
#include"winscene.h"
#include"mybutton.h"
#include"sceneconfig.h"
#include<QPen>
#include "bgmusic.h"

/*************************************************
类名：PlayScene
    游戏场景类

相关函数介绍：
    void zoom();            做默认按钮的按下，弹起特效
    void mousePressEvent(QMouseEvent*e)
                          做有第二个参数的按钮按下特效
    void mouseReleaseEvent(QMouseEvent *e)
                          做有第二个参数的按钮弹起特效

**************************************************/

class ChooseScene;

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit PlayScene(QWidget *parent = nullptr);
   PlayScene(int index);
   void paintEvent(QPaintEvent*);
   void backToChoose(ChooseScene*);
   void Helpersendtips();
   void godHand();
   void getWindow(ChooseScene *);
   void drawLevel();
   void startCounter();
   void createCoins();
   void changeOther(int,int,int);
   void ifWinGame(int );
   void winEvent();
   void recordScore();
   void getBestRecord();
   QString standardTime();



   bgMusic playmusic;
   bool ifwin;
   bool ifadd;
   int barindex;
   tips *tip;
   WinScene *win;
   SceneConfig config;
   QAction *tipsaction;
   QAction *god;
   path *comparation;
   coin *coinset[10][10];
   MyButton *btn_back;
   QVector<path*>helper;
   QVector<path*>answer;
   QVector<QVector<int>> array;
// bool array[4][4];
   QTimer *counter;
   int time;
   ChooseScene *back;

   int best;
   bool recordempty;


signals:

};

#endif // PLAYSCENE_H
