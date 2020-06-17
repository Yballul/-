#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include<QPixmap>
#include<QLabel>
#include<QTimer>
#include<QString>
class coin:public QPushButton
{
public:
    coin(bool,int ,int);
    bool flag;
    int posx;//x坐标
    int posy;//y坐标
    int min=1;//最小图片的序号
    int max=8;//最大图片的序号

    QTimer*id1;//控制金币到银币
    QTimer*id2;//控制银币到金币
    void changeFlag();
};

#endif // COIN_H
