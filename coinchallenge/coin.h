#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include<QPixmap>
#include<QLabel>
#include<QTimer>
#include<QString>
#include<windows.h>
#include "config.h"
/*************************************************

类名：Coin


相关函数介绍：
    changeFlag()                改变硬币的正反面


**************************************************/
class Coin:public QPushButton
{
public:
    Coin(bool, int ,int);
    bool flag;
    int posx;//x坐标
    int posy;//y坐标
    int min=1;//最小图片的序号
    int max=8;//最大图片的序号

    QTimer *id1;//控制金币到银币
    QTimer *id2;//控制银币到金币
    void changeFlag();
};

#endif // COIN_H
