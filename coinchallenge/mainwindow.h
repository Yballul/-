#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QDebug>
#include"mybutton.h"
#include "config.h"
#include"winscene.h"
#include"playscene.h"
#include <QSound>
#include <QSoundEffect>
#include "bgmusic.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*************************************************
类名：MainWindow
    主窗口类，进入游戏的主场景。

相关函数介绍：
    MainWindow(QWidget *parent = nullptr);
                          进行主窗口的初始
    void paintEvent(QPaintEvent *)
                          重写绘图事件

**************************************************/

class ChooseScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    BGMusic mainmusic;


    // 创建选择场景界面
    ChooseScene *choose;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


