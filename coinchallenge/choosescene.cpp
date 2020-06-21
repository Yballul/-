#include "choosescene.h"
#include<Qpainter>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include"mybutton.h"
#include<QTimer>
#include<vector>
#include<QLabel>
#include<QString>
#include<QDebug>
choosescene::choosescene(QWidget *parent) : QMainWindow(parent)
{
    this->resize(500,800);
    this->setFixedSize(500,800);//设定固定大小
    this->setWindowTitle("选择关卡");//设置标题
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));//设置标题的图标

    QMenuBar*bar=menuBar();//设置工具栏
    this->setMenuBar(bar);
    QMenu*startmenu=new QMenu("start");
    bar->addMenu(startmenu);
    QAction*quitaction=new QAction("quit");
    startmenu->addAction(quitaction);

    btn_back=new MyButton(":/res/BackButtonSelected.png");//创建返回按钮
    btn_back->setParent(this);
    btn_back->move(350,600);

    win=new winscene();
    ifwin==false;

   playscene=NULL;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            barchoose.push_back(new MyButton(":/res/LevelIcon.png"));
            barchoose[4*i+j]->setParent(this);
            barchoose[4*i+j]->move((j+1)*90,(i+1)*120);

            connect(barchoose[4*i+j],&MyButton::clicked,[=](){
                barchoose[4*i+j]->zoom();
                QTimer::singleShot(200,this,[=](){
                    qDebug()<<"you choose"<<4*i+j+1<<"bar";
                    playscene=new PlayScene(4*i+j+1);
                    this->hide();
                    playscene->show();
                    playscene->backtochoose(this);
                    playscene->getwindow(this)
                });
            });


            QLabel*label=new QLabel(this);
            label->setFixedSize(barchoose[4*i+j]->width(),barchoose[4*i+j]->height());
            label->setText(QString::number(4*i+j+1));
            label->move((j+1)*90,(i+1)*120);
            label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            label->setAttribute(Qt::WA_TransparentForMouseEvents);//设计鼠标穿透，因为button在label的下面

        }
    }


}

void choosescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap map;//主场景对象
    QPixmap title;//主场景标题
    title.load(":/res/Title.png");
    map.load(":/res/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);//绘制图片，并且按照实际情况进行拉伸
    painter.drawPixmap(10,30,title);//绘制标题图片
}
void choosescene::backtomain(QMainWindow * a)
{
    connect(btn_back,&MyButton::clicked,[=](){
        btn_back->zoom();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            a->show();

        });

    });//点击按钮后返回主窗口
}
