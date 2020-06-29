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
#include "config.h"

/*************************************************
类名：PlayScene
    游戏场景类
相关函数介绍
   void paintEvent(QPaintEvent*);
                            绘图时间，重新绘制游戏场景
   void backToChoose(ChooseScene*);
                            返回选择关卡界面
   void helperSendTips();
                            提示界面
   void godHand();
                            游戏提示相关功能实现函数
   void getWindow(ChooseScene *);
                            获取选择关卡界面
   void drawLevel();
                            绘画出等级
   void startCounter();
                            开启定时器
   void createCoins();
                            创建硬币
   void changeOther(int,int,int);
                            改变硬币的上下左右面
   void ifWinGame(int );
                            赢得胜利之后的函数封装
   void winEvent();
                            获胜事件
   void recordScore();
                            记录游戏时间
   void getBestRecord();
                            获得最优成绩
   QString standardTime();
                            时间标准化
   void Delay();
                            延时函数
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
   void helperSendTips();
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

   BGMusic playmusic;
   bool ifwin;
   bool ifadd;
   int barindex;
   Tips *tip;
   WinScene *win;
   SceneConfig config;
   QAction *tipsaction;
   QAction *god;
   Path *comparation;
   Coin *coinset[10][10];
   MyButton *btn_back;
   QVector<Path*>helper;
   QVector<Path*>answer;
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
