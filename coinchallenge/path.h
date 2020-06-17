#ifndef PATH_H
#define PATH_H

#include <QObject>
#include"mybutton.h"

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
