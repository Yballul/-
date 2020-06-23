#ifndef TIPS_H
#define TIPS_H

#include <QWidget>
#include"path.h"
#include"mybutton.h"
#include<QLabel>
#include<QPixmap>
#include<QFont>
#include<QString>
#include<QMainWindow>
class tips : public QWidget
{
    Q_OBJECT
public:
    tips(path*);
    path *answer;
    MyButton *btn_back;
    void backtoplay(QMainWindow*);

signals:

};

#endif // TIPS_H
