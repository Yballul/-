#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include "mybutton.h"
#include<vector>
#include"winscene.h"
#include "bgmusic.h"
#include "config.h"

using namespace std;

/*************************************************

类名：ChooseScene


相关函数介绍：
    void paintEvent(QPaintEvent *)
                                重写绘图事件
    void backToMain(QMainWindow *)
                                返回主窗口
    void buildUpScene()
                        搭建主要界面


**************************************************/

class MainWindow;

class PlayScene;

class WinScene;

class ChooseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void backToMain(MainWindow *);
    void buildUpScene();

    //创建背景音乐
    BGMusic choosemusic;

    // 创建我的按钮类的数组
    vector<MyButton*>barchoose;

    // 创建返回按钮
    MyButton *btn_back;

    // 创建游戏场景
    PlayScene *playscene;


signals:

};

#endif // CHOOSESCENE_H


