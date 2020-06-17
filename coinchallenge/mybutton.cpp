#include "mybutton.h"

MyButton::MyButton(QString normalim,QString preeim)
{
   normalpath=normalim;
   presspath=preeim;

   QPixmap pix;
   pix.load(normalpath);
   this->setFixedSize(pix.width(),pix.height());//先设置按钮的大小（设置为原图片那么大）
   this->setStyleSheet("QPushButton{border:0px;}");//抹去多余的框内容
   this->setIcon(pix);//设置图片
   this->setIconSize(QSize(pix.width(),pix.height()));//设置图片大小

}

void MyButton::zoom()
{
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");//设定一个动画对象
    animation->setDuration(200);//设计时间间隔
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//设计初始位置
    animation->setEndValue(QRect(this->x(),this->y()+7,this->width(),this->height()));//设计结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->setStartValue(QRect(this->x(),this->y()+7,this->width(),this->height()));//设计初始位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));//设计结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

}
void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(presspath!="")
    {
        QPixmap pix;
        pix.load(this->presspath);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    QPushButton::mousePressEvent(e);
}
void MyButton::mouseRealseEvent(QMouseEvent *e)
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
    QPushButton::mousePressEvent(e);
}
