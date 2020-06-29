#ifndef PATH_H
#define PATH_H

#include <QObject>
#include"mybutton.h"
#include "config.h"

/*************************************************
类名：Path
    存储开发过程中的相关点


**************************************************/

class Path : public QObject
{
    Q_OBJECT
public:
    //explicit path(QObject *parent = nullptr);
    Path(int,int);
    int x;
    int y;
signals:

};

#endif // PATH_H
