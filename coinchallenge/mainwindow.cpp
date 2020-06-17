#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mybutton.h"
#include<QPushButton>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(500,800);
    this->setFixedSize(500,800);//设定固定大小
    this->setWindowTitle("老帮主带你玩金币翻转");//设置标题
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));//设置标题的图标

    MyButton*startBtn=new MyButton(":/res/MenuSceneStartButton.png");//创建开始按钮
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);//开始的位置
    choose=new choosescene;


    connect(startBtn,&MyButton::clicked,[=](){
    startBtn->zoom();
    QTimer::singleShot(200,this,[=](){
        this->hide();
        choose->show();
    });


});//测试开始按钮

    choose->backtomain(this);
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap map;//主场景对象
    QPixmap title;//主场景标题
    title.load(":/res/Title.png");
    map.load(":/res/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);//绘制图片，并且按照实际情况进行拉伸
    painter.drawPixmap(10,30,title);//绘制标题图片
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });//点击退出，退出游戏




}

MainWindow::~MainWindow()
{
    delete ui;
}

