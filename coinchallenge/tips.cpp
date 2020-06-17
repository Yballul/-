#include "tips.h"

tips::tips(path*a)
{

    answer=a;
    this->setFixedSize(500,300);
    this->setWindowTitle("提示窗口");
    btn_back=new MyButton(":/res/BackButtonSelected.png");
    btn_back->setParent(this);
    btn_back->move(this->width()-btn_back->width(),this->height()-btn_back->height());


    QLabel*label=new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(15);
    label->setFont(font);
    label->setGeometry(60,80,350,50);
    label->setText(QString("right path:row %1，column %2").arg(answer->y).arg(answer->x));

}
void tips::backtoplay(QMainWindow *a)
{
    connect(btn_back,&MyButton::clicked,[=](){
        btn_back->zoom();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            a->show();
        });
    });
}
