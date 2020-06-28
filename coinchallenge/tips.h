#ifndef TIPS_H
#define TIPS_H

#include <QWidget>
#include"path.h"
#include"mybutton.h"
#include<QLabel>
#include<QPixmap>
#include<QFont>
#include<QString>
#include<QMainWindow>
#include "config.h"

/*************************************************
类名：Tips

游戏提示功能函数实现之一
**************************************************/


class tips : public QWidget
{
    Q_OBJECT
public:
    tips(path*);
    path *answer;
    MyButton *btn_back;
    void backtoPlay(QMainWindow*);

signals:

};

#endif // TIPS_H
