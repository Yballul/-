#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include<QString>
#include<QPropertyAnimation>
#include<QTimer>
class MyButton : public QPushButton
{
    Q_OBJECT
public:

    MyButton(QString normalim,QString preeim="");
    QString normalpath;//默认的显示路径
    QString presspath;//按下以后的显示路径
    void  mousePressEvent(QMouseEvent*e);
    void  mouseRealseEvent(QMouseEvent*e);
    void zoom();


signals:

};

#endif // MYBUTTON_H
