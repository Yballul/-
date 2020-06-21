#include "coin.h"
#include<QPushButton>

Coin::Coin(bool a,int b,int c)
{
    flag=a;
    posx=b;
    posy=c;
    QPixmap pix;
    id1=new QTimer;
    id2=new QTimer;
    if(a)
    {
        pix.load(COIN_GOLD);
    }
    else
    {
        pix.load(COIN_SILVER);

    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    connect(id1,&QTimer::timeout,[=](){

        QPixmap pix;
        pix.load(QString(":/res/Coin000%1.png").arg(min++));
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(min>max)
        {
            min=1;//重置最小值
            id1->stop();

        }
    });
    connect(id2,&QTimer::timeout,[=](){
        QPixmap pix;
        pix.load(QString(":/res/Coin000%1.png").arg(max--));
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(max<min)
        {
            max=8;//重置最大值
            id2->stop();

        }
    });
}

void Coin::changeFlag()
{
    if(flag)//金币翻银币
    {
        id1->start(30);//启动定时器
        flag=!flag;//转换图片

     }
    else//银币翻金币
    {
        id2->start(30);
        flag=!flag;
    }
}

