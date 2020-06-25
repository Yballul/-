#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "sceneconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QVector<QVector<int>> array;
    SceneConfig config;
    auto pos = config.mData.find(4);

    qDebug()<<"**************"<<endl;
    for(int i=0;i < pos->first().size();++i)
    {
        array.push_back(config.mData[4][i]);
        qDebug()<<config.mData[4][i]<<" ";
    }
    qDebug()<<"**************"<<endl;
    return a.exec();
}
