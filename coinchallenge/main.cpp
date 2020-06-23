#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "sceneconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    SceneConfig config;


    return a.exec();
}
