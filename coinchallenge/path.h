#ifndef PATH_H
#define PATH_H

#include <QObject>
#include"mybutton.h"
#include "config.h"

/*************************************************
类名：path
    存储开发过程中的相关点


**************************************************/

class path : public QObject
{
    Q_OBJECT
public:
    //explicit path(QObject *parent = nullptr);
    path(int,int);
    int x;
    int y;
signals:

};

#endif // PATH_H
