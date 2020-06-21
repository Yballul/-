#include <mybutton.h>
#include <QSound>
#include "coin.h"
#include "config.h"

/*************************************************
类名：Sound
    游戏音效类

功能介绍：
    实现程序内各种按钮的音效



**************************************************/


#ifndef SOUND_H
#define SOUND_H

#include <QObject>

class Sound : public QObject
{
    Q_OBJECT
public:
    Sound(Coin*, QString);
    Sound(MyButton*, QString);

signals:

};

#endif // SOUND_H
