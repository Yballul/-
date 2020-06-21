#include "winscene.h"
#include<QPainter>
#include "sound.h"
#include "choosescene.h"
#include "mybutton.h"
WinScene::WinScene(int t,int u,int v,bool a,bool b)
{
    //先实现菜单栏
       this->resize(500,800);
       QMenuBar*bar=menuBar();
       this->setMenuBar(bar);
       QMenu*startmenu=new QMenu("start");
       bar->addMenu(startmenu);
       QAction*quitaction=new QAction("exit");
       startmenu->addAction(quitaction);
       connect(quitaction,&QAction::triggered,[=](){
           this->close();
       });
       QLabel*label=new QLabel(this);
       QFont font;
       font.setFamily("华文新魏");
       font.setPointSize(30);
       label->setFont(font);
       label->setGeometry(150,300,400,40);
       label->setText("游戏胜利");

       //初始化一些基本成员
       best=u;
       breakrecord=a;
       empty=b;
       index=v;
       timeplay=t;

       winmusic.setBasic(this, WIN_SOUND);



       btn_back=new MyButton(BACK_BUTTON);
       btn_back->setParent(this);
       btn_back->move(this->width()-btn_back->width(),this->height()-btn_back->height());
       Sound(btn_back, BACK_SOUND);


}
void WinScene::paintEvent(QPaintEvent*e)
{

    QPainter painter(this);
    QPixmap map;//主场景对象
    QPixmap title;//主场景标题
    title.load(TITLE);
    map.load(PLAY_BG);//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);//绘制图片，并且按照实际情况进行拉伸
    painter.drawPixmap(10,30,title);//绘制标题图片
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::white);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(30);
    painter.setFont(font);
    painter.setPen(pen);
    int minute=timeplay/60;
    int second=timeplay%60;

    QString timeshow=this->standardTime(minute,second);
    //写上标准的玩家通关时间
    painter.drawText(120,250,timeshow);

    int minute1=best/60;
    int second1=best%60;


    pen.setColor(Qt::blue);
    painter.setPen(pen);
    //写上最高纪录时间
    QString timeshow1=this->standardTime(minute1,second1);

    if(empty)
    {
        //没有记录的情况
        painter.drawText(70,400,"当前无任何记录");
    }
    else if(breakrecord&&!empty)
    {
        //打破了纪录的状况
        painter.drawText(70,400,"恭喜你打破记录");
        painter.drawText(180,450,"原纪录:");
        painter.drawText(190,500,timeshow1);
    }
    else if(!breakrecord&&!empty)
    {
        //没打破纪录的状况
        painter.drawText(180,400,"原纪录:");
        painter.drawText(190,450,timeshow1);
    }
    //设置画笔颜色，字体大小
    pen.setColor(Qt::white);
    font.setPointSize(40);
    painter.setFont(font);
    painter.setPen(pen);
    painter.drawText(165,200,QString("第%1关").arg(index));
}
QString WinScene::standardTime(int minute,int second)
{
    QString minuteshow;
    QString secondshow;
    if(minute<10)
    {
        minuteshow=QString("0%1").arg(minute);
    }
    else
    {
        minuteshow=QString("%1").arg(minute);
    }
    if(second<10)
    {
        secondshow=QString("0%1").arg(second);
    }
    else
    {
        secondshow=QString("%1").arg(second);

    }

    QString timeshow=QString("用时:")+minuteshow+QString(":")+secondshow;
    return timeshow;
}
void WinScene::backToMainScene(ChooseScene *a)
{
    //实现返回功能
    connect(btn_back,&MyButton::clicked,[=](){
        btn_back->zoom();
        QTimer::singleShot(200,this,[=](){
            //隐藏本窗口
            this->hide();
            //胜利背景音乐
            winmusic.check();
            a->choosemusic.play();
            //显示选择窗口
            a->show();
        });
    });
}

