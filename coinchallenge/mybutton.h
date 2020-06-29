#ifndef MYBUTTON_H
#define MYBUTTON_H


/*************************************************

类名：MyButton
    接收图片参数，第一个参数为按钮的初始状态，第二个参数为
 按钮按下之后的状态，如果第二个参数为空，那么将会给设置默认
 按钮按下状态。

相关函数介绍：
    void zoom();            做默认按钮的按下，弹起特效
    void mousePressEvent(QMouseEvent*e)
                          做有第二个参数的按钮按下特效
    void mouseReleaseEvent(QMouseEvent *e)
                          做有第二个参数的按钮弹起特效

**************************************************/

#include <QPushButton>
#include<QString>
#include<QPropertyAnimation>
#include<QTimer>
#include "config.h"

class MyButton : public QPushButton
{
    Q_OBJECT
public:

    MyButton(QString normalim,QString preeim="");

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void zoom();


    QString normalpath;//默认的显示路径
    QString presspath;//按下以后的显示路径

signals:

};

#endif // MYBUTTON_H
