#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#define inf 0x3f3f3f3f
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
#include<ctime>
#include "bgmusic.h"
#include<windows.h>
#include<iostream>
#include <QStack>

/*************************************************
类名：PlayScene
    游戏场景类
相关函数介绍
   void paintEvent(QPaintEvent*);
                            绘图时间，重新绘制游戏场景
   void backToChoose(ChooseScene*);
                            返回选择关卡界面
   void Helpersendtips();
                            提示界面
   void godHand();
                            帮助玩家执行下一步
   void getWindow(ChooseScene *);
                            获取选择关卡界面
   void drawLevel();

   void startCounter();
   void createCoins();
   void changeOther(int,int,int);
   void ifWinGame(int );
   void winEvent();
   void recordScore();
   void getBestRecord();
   QString standardTime();
   void Delay();

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
   void Delay();
   void dfs(int x, int y, int step);
   QString standardTime();
   void recordArray(int,int);
   void nowArrayInit(int index);
   void solveArray();
   void swap(int x,int y);
   void stackOutput();
   bool check();

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
   int minn = inf;
   QTimer *test;
   QStack<int>ret_x;
   QStack<int>ret_y;
   QStack<int>pos_x;
   QStack<int>pos_y;

signals:

};

#endif // PLAYSCENE_H
