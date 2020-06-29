#include "playscene.h"
#include "sound.h"
#include <QTimer>
#include "choosescene.h"
#include "mybutton.h"
#include "coin.h"
#include "bgmusic.h"


PlayScene::PlayScene(int index)
{
    ifadd = true;
    //胜利状态先设为False
    ifwin = false;
    tip = NULL;
    comparation = NULL;
    //设置固定大小
    this->setFixedSize(500,800);
    //设置窗口标题
    this->setWindowTitle(QString("游戏关卡%1").arg(index));
    //设置标题图标
    this->setWindowIcon(QIcon(COIN_GOLD));
    //初始化游戏关卡的序号
    barindex=index;
    //读取以往玩家的记录
    this->getBestRecord();

    // 设置菜单栏
    QMenuBar *bar=menuBar();
    this->setMenuBar(bar);
    //设置“开始”菜单项
    QMenu *startmenu=new QMenu("开始");
    bar->addMenu(startmenu);
    //设置“退出”菜单项
    QAction *quitaction = new QAction("退出");
    //设置“提示”菜单项
    tipsaction = new QAction("tips");
    //设置“外挂”菜单项C
    god = new QAction("god's hand");
    helperSendTips();
    //设置“提示”菜单项
    QAction *dfsaction = new QAction("提示");
    startmenu->addAction(dfsaction);


    startmenu->addAction(quitaction);
//    startmenu->addAction(tipsaction);
//    startmenu->addAction(god);
    if(index<=9)
    {
        startmenu->addAction(dfsaction);
    }

//    this->godHand();
    win = NULL;

    //实现退出功能
    connect(quitaction,&QAction::triggered,[=](){
        this->close();
    });

    // 测试dfs功能
    connect(dfsaction,&QAction::triggered,[=](){
        solveArray();
    });

    //设置背景音乐
    playmusic.setBasic(this, BASIC_MUSIC);
    playmusic.setButton();

    //创建返回按钮
    btn_back=new MyButton(BACK_BUTTON);
    btn_back->setParent(this);
    btn_back->move(350,600);
    Sound(btn_back, BACK_SOUND);

    //启动定时器，开始更新时间
    this->startCounter();

    //创造金币
    this->createCoins();


}
void PlayScene::createCoins()
{

    //创建金币的图片背景+创建金币
    auto pos = config.mData.find(barindex);

    for(int i=0;i < pos->first().size();++i)
    {
        array.push_back(config.mData[barindex][i]);

    }
    for(int i=0;i < pos->first().size();i++)
    {
        for(int j=0;j < pos->first().size();j++)
        {

            //设置金币背后的灰色方块
            QLabel * bg = new QLabel(this);
            QPixmap pix;
            pix.load(BOADR_NODE);
            //设置灰色方块的位置
            bg->setGeometry(126+i*50+(5-pos->first().size())*22,220+j*50,pix.width(),pix.height());
            bg->setPixmap(pix);

            //创造金币对象
            Coin *little = new Coin(array[i][j],i+1,j+1);
            little->setParent(this);
            //设置金币的位置
            little->move(126+i*50+(5-pos->first().size())*22,222+j*50);
            //初始化金币集
            coinset[i][j] = little;
            Sound(coinset[i][j], FLIP_SOUND);
            //点击金币，实现翻转
            connect(little,&Coin::clicked,[=](){
                //被点击的金币自身要翻转
                little->changeFlag();

                array[i][j] = !(array[i][j]);
                if(comparation!=NULL)
                {
                    if(comparation->x!=i+1 || comparation->y!=j+1)
                    {
                        ifadd=true;
                    }//看看是不是按照按照提示走的

                }
                if(ifadd)
                {
                    helper.push_back(new Path(i+1,j+1));//把玩家的路径压入向量
                }
                //自身翻转后延后一段时间，然后四周金币翻转
                int size = pos->first().size();
                QTimer::singleShot(100,this,[=](){
                    //翻转四周金币
                    this->changeOther(i,j,size);
                    ifwin=true;
                    //检查是否获胜
                    this->ifWinGame(size);
                });
                    //判断是否胜利，如果是真就调用胜利事件
               QTimer::singleShot(500,this,[=](){
                   if(ifwin)
               {
                      this->winEvent();
               }
               });
           });
        }
   }
}
void PlayScene::winEvent()
{
    //暂停定时器，计时结束
    counter->stop();
    //隐藏当前窗口
    this->hide();
    //停止播放音乐
    playmusic.check();
    //创建胜利场景
    win=new WinScene(time,best,barindex,time<best?true:false,recordempty);
    //为返回选择场景的“返回”提供场景
    win->backToMainScene(back);
    //播放胜利场景音乐
    win->winmusic.playForOnce();
    //展现胜利窗口
    win->show();
    //记录玩家本关的通关时间
    this->recordScore();

}
void PlayScene::ifWinGame(int size)
{

    for(int a=0; a<size;++a)
    {
        for(int b=0; b<size;++b)
        {
            if(coinset[a][b]->flag==false)
            {
                //如果有一个银币，就是没有完成游戏
                ifwin=false;
                break;
            }
        }
    }
}
void PlayScene::changeOther(int i, int j, int size)
{
    if(coinset[i][j]->posx+1 <= size)
    {
        coinset[i+1][j]->changeFlag();
        array[i+1][j]=!(array[i+1][j]);
    }//检测右边是否有硬币需要翻转

    if(coinset[i][j]->posx-1 >= 1)
    {
        coinset[i-1][j]->changeFlag();
        array[i-1][j]=!(array[i-1][j]);
    }//检测左边是否有硬币需要翻转

    if(coinset[i][j]->posy+1 <= size)
    {
        coinset[i][j+1]->changeFlag();
        array[i][j+1]=!(array[i][j+1]);
    }//检测下边硬币是否需要反转

    if(coinset[i][j]->posy-1 >= 1)
    {
        coinset[i][j-1]->changeFlag();
        array[i][j-1]=!(array[i][j-1]);
    }//检测上边硬币是否需要反转
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //设置主场景对象
    QPixmap map;
    //设置主场景标题
    QPixmap title;
    //加载标题图片
    title.load(TITLE);
    //加载背景图片
    map.load(PLAY_BG);
    //绘制图片，并且按照实际情况进行拉伸
    painter.drawPixmap(0,0,this->width(),this->height(),map);
    //绘制标题图片
    painter.drawPixmap(10,30,title);
    //设置画笔的宽度和颜色
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::white);
    //设置字体类型以及大小
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(30);
    painter.setFont(font);
    painter.setPen(pen);
    //将秒数变成标准时间格式 几分几秒 00：00
    QString timeshow=this->standardTime();
    painter.drawText(190,200,timeshow);

}

QString PlayScene::standardTime()
{
    //得到分钟数
    int minute=time/60;
    //得到不足一分钟的秒数
    int second=time%60;
    QString minuteshow;
    QString secondshow;
    if(minute<10)
    {
        //如果小于10分钟，表达为0X分
        minuteshow=QString("0%1").arg(minute);
    }
    else
    {   //如果是大于等于10分钟，表达为X分
        minuteshow=QString("%1").arg(minute);
    }
    if(second<10)
    {
        //如果小于10秒，表达为0X秒
        secondshow=QString("0%1").arg(second);
    }
    else
    {
        //如果是大于等于10秒，表达为X秒
        secondshow=QString("%1").arg(second);

    }
    //标准时间格式
    QString timeshow=minuteshow+QString(":")+secondshow;
    return timeshow;
}

void PlayScene::backToChoose(ChooseScene *a)
{   
        connect(btn_back,&MyButton::clicked,[=](){
            btn_back->zoom();
            QTimer::singleShot(200,this,[=](){
                this->hide();
                playmusic.check();
                a->choosemusic.play();
                a->setGeometry(this->geometry());
                a->show();
            });

        });//点击按钮后返回主窗口
}

void PlayScene::helperSendTips()
{

    connect( tipsaction,&QAction::triggered,[=](){
        //玩家已经开始走了，先比较一下玩家的路径和答案的路径
        bool same=true;
        int border;
        border=helper.size()<=answer.size()?helper.size():answer.size();
        for(int i=0;i<border;i++)//先确定哪个元素比较多
        {
            if(helper[i]->x!=answer[i]->x||helper[i]->y!=answer[i]->y)//比较路径是否相等
            {
                same=false;
                ifadd=true;
            }
        }
            if(same)
            {
                tip=new Tips(answer[helper.size()]);//传输一步正确的
                ifadd=true;
            }
            else
            {
                tip=new Tips(helper[helper.size()-1]);//先返回到最初的设定
                ifadd=false;
                comparation=new Path(helper[helper.size()-1]->x,helper[helper.size()-1]->y);

                helper.pop_back();
            }


    tip->backtoPlay(this);
    tip->show();
    });
}

void PlayScene::godHand()
{
    connect(god, &QAction::triggered,[=](){
        bool same=true;
        int border;
        border = helper.size()<=answer.size() ? helper.size() : answer.size();
        for(int i=0;i<border;i++)//先确定哪个元素比较多
        {
            if(helper[i]->x!=answer[i]->x||helper[i]->y!=answer[i]->y)//比较路径是否相等
            {
                same=false;
                ifadd=true;
            }
        }

            if(same)
            {
                if(answer.size()-1==helper.size())
                {
                    ifwin=true;
                }//如果已经走到了倒数第二步了，那么下面的程序就是把最后一步走完，所以这里直接将ifwin设为trueninage
                coinset[answer[helper.size()]->x-1][answer[helper.size()]->y-1]->changeFlag();
                int  i=answer[helper.size()]->x-1;
                int  j=answer[helper.size()]->y-1;
                QTimer::singleShot(100,this,[=](){
                    if(coinset[i][j]->posx+1<=4)
                    {
                        coinset[i+1][j]->changeFlag();
                        array[i+1][j]=!(array[i+1][j]);
                    }//检测右边是否有硬币需要翻转
                    if(coinset[i][j]->posx-1>=1)
                    {
                        coinset[i-1][j]->changeFlag();
                         array[i-1][j]=!(array[i-1][j]);
                    }//检测左边是否有硬币需要翻转
                    if(coinset[i][j]->posy+1<=4)
                    {
                        coinset[i][j+1]->changeFlag();
                         array[i][j+1]=!(array[i][j+1]);
                    }//检测下边硬币是否需要反转
                    if(coinset[i][j]->posy-1>=1)
                    {
                        coinset[i][j-1]->changeFlag();
                        array[i][j-1]=!(array[i][j-1]);
                    }//检测上边硬币是否需要反转
                });

                ifadd=true;
                if(ifadd)
               {

                helper.push_back(new Path(i+1,j+1));//把外挂的路径压入向量

               }

            }
            else
            {
                coinset[helper[helper.size()-1]->x-1][helper[helper.size()-1]->y-1]->changeFlag();
                //先返回到最初的设定
                int  i=helper[helper.size()-1]->x-1;
                int  j=helper[helper.size()-1]->y-1;
                  QTimer::singleShot(100,this,[=](){
                      if(coinset[i][j]->posx+1<=4)
                      {
                          coinset[i+1][j]->changeFlag();
                          array[i+1][j]=!(array[i+1][j]);
                      }//检测右边是否有硬币需要翻转
                      if(coinset[i][j]->posx-1>=1)
                      {
                          coinset[i-1][j]->changeFlag();
                           array[i-1][j]=!(array[i-1][j]);
                      }//检测左边是否有硬币需要翻转
                      if(coinset[i][j]->posy+1<=4)
                      {
                          coinset[i][j+1]->changeFlag();
                           array[i][j+1]=!(array[i][j+1]);
                      }//检测下边硬币是否需要反转
                      if(coinset[i][j]->posy-1>=1)
                      {
                          coinset[i][j-1]->changeFlag();
                          array[i][j-1]=!(array[i][j-1]);
                      }//检测上边硬币是否需要反转
                  });
                ifadd=false;
                helper.pop_back();//删除掉末尾的路径，不然会陷入死循环
                if(ifadd)
               {
                helper.push_back(new Path(i+1,j+1));//把外挂的路径压入向量
               }
            }

            QTimer::singleShot(500,this,[=](){
                if(ifwin)
            {
                counter->stop();
                this->hide();
                win=new WinScene(time,best,barindex,time<best?true:false,recordempty);
                win->backToMainScene(back);
                win->show();
                this->recordScore();
            }});
    });
}

void PlayScene::getWindow(ChooseScene *a)
{
    //将back传递给this中的win成员，达到在win场景中按下back按钮，回到选择场景
    back = a;
}

void PlayScene::recordScore()
{
    //记录文件路径
    QString filepath=QString("record.txt");
    QFile file(filepath);
    //用追加的方式打开文件，写入数据
    file.open(QIODevice::Append);
    //把玩家此次通关的用时记录进文件中
    QString a=QString("%1").arg(time)+QString("\n");
    QByteArray b=a.toUtf8();
    file.write(b);
    //关闭文件
    file.close();
}

void PlayScene::getBestRecord()
{
    QByteArray arr;
    //记录文件路径
    QString filepath=QString("record.txt");
    QFile file(filepath);
    //用只读的方式读取文件
    file.open(QIODevice::ReadOnly);
    //用容器储存已有的记录
    QVector<int>record;
    //读取文件中每个记录，并记录下来
    while(!file.atEnd())
    {
      bool ok;
      arr=file.readLine();
      QString b=QString::fromLocal8Bit(arr);
      int a=b.toInt(&ok,10);
      record.push_back(a);
      qDebug()<<"记录"<<b<<" "<<a;
    }
    //关闭文件
    file.close();
    //如果容器的size不为0，也就代表了文件中原是有记录的
    //如果容器的size为0，说明是文件中原来没有记录的
    if(record.size()!=0)
    {   int a=record[0];
        for(int i=1;i<record.size();++i)
        {
            if(a>=record[i])
            {
                a=record[i];
            }
        }
        best=a;
        recordempty == false;
    }
    else
    {
        recordempty=true;
        //如果记录为空，那么最好的分数记为0（规定的一个无效记录值）
        best=0;
        qDebug()<<"无记录";
    }
}

void PlayScene::drawLevel()
{
    //标明关卡序号
    //设置标签
    QLabel *label=new QLabel;
    label->setParent(this);
    QFont font;
    //设置字体类型及大小
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    //标明关卡序号
    label->setGeometry(30, this->height()-50,120,50);
    label->setText(QString("Level:%1").arg(barindex));
}

void PlayScene::startCounter()
{
    //初始化玩家所用的时间（为0），启动记录玩家时间的定时器，每隔一秒记录一次
    time=0;
    counter=new QTimer(this);
    counter->start(1000);
    counter->start(1000);
    //每触发一次定时事件，就更新一次time
    connect(counter,&QTimer::timeout,[=](){
        ++time;
        this->update();
    });
}

void PlayScene::nowArrayInit(int index)
{
    auto pos = config.mData.find(index);
    for(int i=0;i < pos->first().size();++i)
    {
        array.push_back(config.mData[index][i]);
    }

}

void PlayScene::recordArray(int x,int y)
{
    auto pos = config.mData.find(barindex);
    for(int i=0;i < pos->first().size();++i)
    {
        for(int j=0;j < pos->first().size();++j)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    if(x < pos->first().size()-1)
    {
        array[x+1][y]=!(array[x+1][y]);
    }//检测下边是否有硬币需要翻转

    if(x >= 1)
    {
        array[x-1][y]=!(array[x-1][y]);
    }//检测上边是否有硬币需要翻转

    if(y < pos->first().size()-1)
    {
        array[x][y+1]=!(array[x][y+1]);
    }//检测右边硬币是否需要反转

    if(y >= 1)
    {
        array[x][y-1]=!(array[x][y-1]);
    }//检测左边硬币是否需要反转

    for(int i=0;i < pos->first().size();++i)
    {
        for(int j=0;j < pos->first().size();++j)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void PlayScene::solveArray()
{
    minn = inf;
    dfs(0,0,0);
    stackOutput();
    if (minn <= 16)    //有最小值
        cout << minn << endl;
    else
    {
        cout << "impossible" << endl;
    }
}

void PlayScene::dfs(int x,int y,int step)
{
    auto pos = config.mData.find(barindex);
    if (step > pos->first().size()*pos->first().size())   //翻了16次  已经不能再求出了
    {
       return;
    };

    if (check())   //检查是否达到目标状态
    {
        if (step < minn)   //维护最小值
        {
            minn = step;
            ret_x = pos_x;
            ret_y = pos_y;
            return;
        }
    }

    if (y >= pos->first().size())   //因为是按行走的，当走到行末时，就需要跳到下一行的第一个
    {
        x++;
        y = 0;
    }
    if (x >= pos->first().size())  //矩阵找完了
        return;
    for (int i = 0; i < 2; i++)  //每个点的两种状态
    {
        if (i == 0)   //翻
        {
            pos_x.push(x);
            pos_y.push(y);
            swap(x, y);
            dfs(x, y + 1, step + 1);
            swap(x, y);   //把翻过的点恢复
            pos_x.pop();
            pos_y.pop();
        }
        else    //不翻
            dfs(x, y + 1, step);
    }
}

void PlayScene::swap(int x,int y)
{
    auto pos = config.mData.find(barindex);
    array[x][y] = !array[x][y];
    if(x < pos->first().size()-1)
    {
        array[x+1][y]=!(array[x+1][y]);
    }//检测下边是否有硬币需要翻转

    if(x >= 1)
    {
        array[x-1][y]=!(array[x-1][y]);
    }//检测上边是否有硬币需要翻转

    if(y < pos->first().size()-1)
    {
        array[x][y+1]=!(array[x][y+1]);
    }//检测右边硬币是否需要反转

    if(y >= 1)
    {
        array[x][y-1]=!(array[x][y-1]);
    }//检测左边硬币是否需要反转
}

bool PlayScene::check()
{
    auto pos = config.mData.find(barindex);
    int flag=1;
    for (int i = 0; i < pos->first().size(); i++)
    {
      for (int j = 0; j < pos->first().size(); j++)
      {
          if (array[i][j] != flag)
          {
              return 0;
          }
      }
    }
    return 1;
}

void PlayScene::stackOutput()
{
    auto pos = config.mData.find(barindex);
    while(!ret_x.empty())
    {
        cout << ret_x.top()<<" "<<ret_y.top()<<endl;
        coinset[ret_x.top()][ret_y.top()]->changeFlag();
        cout<<pos->first().size();
        changeOther(ret_x.top(),ret_y.top(),pos->first().size());
        ret_x.pop();
        ret_y.pop();
        break;
    }

    this->ifwin = true;
    for(int i = 0;i<pos->first().size();i++)
    {
        for(int j = 0 ;j<pos->first().size();j++)
        {
            if(coinset[i][j]->flag==false)
            {
                this->ifwin = false;
                break;
            }
        }
    }

    if(this->ifwin==true)
    {
        Sleep(1000); //这里延迟1秒
        winEvent();
    }

}
