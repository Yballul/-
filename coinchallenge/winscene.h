#ifndef WINSCENE_H
#define WINSCENE_H

#include<QMainWindow>
#include<QPainter>
#include<QPaintDevice>
#include<QPixmap>
#include<QMenu>
#include<QMenuBar>
#include<QLabel>
#include<QAction>
#include<QFont>
#include<QPen>
#include"mybutton.h"
#include "bgmusic.h"
#include "config.h"

/*************************************************

类名：WinScene
    胜利界面的实现。

相关函数介绍：
    void paintEvent(QPaintEvent *e)
                          重写绘图事件
    void backToMainScene(QMainWindow*)
                          返回按钮的实现
    void mouseReleaseEvent(QMouseEvent *e)
                          做有第二个参数的按钮弹起特效

**************************************************/

class ChooseScene;

class WinScene : public QMainWindow
{
    Q_OBJECT
public:
    WinScene(int a,int b,int c,bool d,bool e);
    void paintEvent(QPaintEvent *e);
    void backToMainScene(ChooseScene *);
    QString standardTime(int,int);
    MyButton *btn_back;
    int timeplay;
    int best;
    int index;
    bool breakrecord;
    bool empty;
    BGMusic winmusic;


signals:

};

#endif // WINSCENE_H
