﻿#include "mybutton.h"

MyButton::MyButton(QString normalim,QString preeim)
{

   normalpath=normalim;
   presspath=preeim;

   QPixmap pix;
   pix.load(normalpath);
   //先设置按钮的大小（设置为原图片那么大）
   this->setFixedSize(pix.width(), pix.height());
   //抹去多余的框内容
   this->setStyleSheet("QPushButton{border:0px;}");
   //设置图片
   this->setIcon(pix);
   //设置图片大小
   this->setIconSize(QSize(pix.width(), pix.height()));

}

void MyButton::zoom()
{
    // 创建一个动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    // 设计动画时间间隔
    animation->setDuration(200);

    // 设置动画的弹跳曲线(具体可以查阅帮助文档)
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 设置动画按下的效果
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+7,this->width(),this->height()));


    // 设计动画弹起的效果
    animation->setStartValue(QRect(this->x(),this->y()+7,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    // 执行动画
    animation->start();

}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(presspath!="")
    {
        QPixmap pix;
        pix.load(this->presspath);
        //设置固定大小
        this->setFixedSize(pix.width(),pix.height());
        //消除边框
        this->setStyleSheet("QPushButton{border:0px}");
        //设置按钮图标
        this->setIcon(pix);
        //设置按钮图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    QPushButton::mousePressEvent(e);
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(presspath!="")
    {
        QPixmap pix;
        pix.load(this->normalpath);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    QPushButton::mouseReleaseEvent(e);
}
