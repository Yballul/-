#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mybutton.h"
#include<QPushButton>
#include<QTimer>
#include "choosescene.h"
#include "sound.h"
#include "bgmusic.h"

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
    this->setWindowIcon(QIcon(COIN_GOLD));


    // 开始按钮的制作
    MyButton *startBtn = new MyButton(START_BUTTON);
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    Sound(startBtn, TAP_SOUND);
    choose=new ChooseScene;

    //设置背景音乐
    mainmusic.setBasic(this, MAIN_MUSIC);
    mainmusic.setButton();
    mainmusic.play();




    // 将开始按钮与下一个场景进行绑定转换
    connect(startBtn,&MyButton::clicked,[=](){
    startBtn->zoom();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            mainmusic.check();
            choose->setGeometry(this->geometry());
            choose->show();
            choose->choosemusic.play();
    });

});
    // 点击按钮返回主界面的设置
    choose->backToMain(this);


}

// 重写绘图事件
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap map;//主场景对象
    map.load(MENU_BG);//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),map);//绘制图片，并且按照实际情况进行拉伸

}


MainWindow::~MainWindow()
{
    delete ui;
}

