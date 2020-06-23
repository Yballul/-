#ifndef SCENECONFIG_H
#define SCENECONFIG_H
#include <QVector>
#include <QMap>

class SceneConfig
{
public:
    SceneConfig();

    QMap<int, QVector<QVector<int>>> mData;
};

#endif // SCENECONFIG_H
