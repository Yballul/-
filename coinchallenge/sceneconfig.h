#ifndef SCENECONFIG_H
#define SCENECONFIG_H
#include <QVector>
#include <QMap>


/*************************************************
类名：SceneConfig

关卡初始化
**************************************************/

class SceneConfig
{
public:
    SceneConfig();

    QMap<int, QVector<QVector<int>>> mData;
};

#endif // SCENECONFIG_H
