#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mybutton.h"
#include<QPushButton>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 系统创建ui界面默认调用
    ui->setupUi(this);

    // 点击退出，退出游戏
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });


    // 重新调整窗口大小并且设置固定大小
    this->resize(500,800);
    this->setFixedSize(500,800);//设定固定大小

    // 设置游戏的标题和图标
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    // 开始按钮的制作
    MyButton *startBtn = new MyButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    choose=new ChooseScene;

    // 将开始按钮与下一个场景进行绑定转换
    connect(startBtn,&MyButton::clicked,[=](){
    startBtn->zoom();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            choose->show();
    });

});
    // 点击按钮返回主界面的设置
    choose->backtomain(this);
}

// 重写绘图事件
void MainWindow::paintEvent(QPaintEvent *event)
{
    // 创建一个绘画家对象
    QPainter painter(this);

    // 绘制主场景标题
    QPixmap title;//主场景标题
    title.load(":/res/Title.png");
    painter.drawPixmap(10,30,title);//绘制标题图片

    // 绘制主场景对象，并且按照实际情况进行拉伸
    QPixmap map;
    map.load(":/res/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);

}

MainWindow::~MainWindow()
{
    delete ui;
}

