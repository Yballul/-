#include <QMainWindow>
#include <QSound>


/*************************************************
类名：bgMusic
    背景音乐类

相关函数介绍：
    void check()    检查是否继续播放背景音乐
    void play()     播放背景音乐
    void playForOnce() 只播放一次背景音乐
    void set(QMainWindow*, QString)
                    设置父亲窗体，播放路径
    void setButton()    创建静音按钮


**************************************************/

#ifndef BGMUSIC_H
#define BGMUSIC_H

#include <QObject>

class bgMusic : public QObject
{
    Q_OBJECT
public:
    bgMusic();
    void check();
    void play();
    void setBasic(QMainWindow*, QString);
    void setButton();
    void playForOnce();
    QMainWindow* window;
    QString address;
    QSound * sound;

signals:

};

#endif // BGMUSIC_H
