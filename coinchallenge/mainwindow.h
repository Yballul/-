#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QDebug>
#include"mybutton.h"
#include"choosescene.h"
#include"winscene.h"
#include"playscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    choosescene*choose;
    winscene*win;
    void send1();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
