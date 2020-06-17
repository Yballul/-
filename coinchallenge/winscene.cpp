#include "winscene.h"
#include<QPainter>
winscene::winscene(QWidget *parent) : QMainWindow(parent)
{      //先实现菜单栏
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



       btn_back=new MyButton(":/res/BackButton.png");
       btn_back->setParent(this);
       btn_back->move(this->width()-btn_back->width(),this->height()-btn_back->height());




}
void winscene::paintEvent(QPaintEvent*e)
{

    QPainter painter(this);
    QPixmap map;//主场景对象
    QPixmap title;//主场景标题
    title.load(":/res/Title.png");
    map.load(":/res/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);//绘制图片，并且按照实际情况进行拉伸
    painter.drawPixmap(10,30,title);//绘制标题图片

}
void winscene::backtomainscene(QMainWindow*a)
{
    connect(btn_back,&MyButton::clicked,[=](){
        btn_back->zoom();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            a->show();
        });
    });
}

