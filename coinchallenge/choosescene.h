#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include "mybutton.h"
#include<vector>
#include "playscene.h"
#include"winscene.h"

using namespace std;
class choosescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit choosescene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void backtomain(QMainWindow*);
    vector<MyButton*>barchoose;
    MyButton*btn_back;
    PlayScene *playscene;
    bool ifwin;
    winscene*win;
    void send2(QMainWindow*);
signals:

};

#endif // CHOOSESCENE_H
