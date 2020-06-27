#include "sceneconfig.h"

SceneConfig::SceneConfig()
{
    // 关卡一
    int array1[3][3] = {{1,1,1},
                        {1,1,0},
                        {1,0,0}};

    QVector<QVector <int>>v;
    for(int i = 0; i < 3; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 3; j++)
        {
            v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1,v);

    v.clear();

    // 关卡二
    int array2[3][3] = {{1,0,1},
                        {0,0,0},
                        {1,0,1}};

    for(int i = 0; i < 3; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 3; j++)
        {
            v1.push_back(array2[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2,v);

    v.clear();
    int array3[3][3] = {{0,0,1},
                        {0,1,0},
                        {1,0,0}};


    for(int i = 0; i < 3; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 3; j++)
        {
            v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3,v);

    v.clear();
    int array4[3][3] = {{0,1,0},
                        {1,1,1},
                        {0,1,0}};


    for(int i = 0; i < 3; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 3; j++)
        {
            v1.push_back(array4[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(4,v);

    v.clear();

    int array5[4][4] = {{0,0,1,1},
                        {0,1,0,1},
                        {1,0,0,0},
                        {1,1,0,1}};


    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(array5[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5,v);

    v.clear();

    int array6[4][4] = {{1,1,1,0},
                        {0,0,0,1},
                        {0,1,1,0},
                        {1,1,0,1}};


    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(array6[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(6,v);

    v.clear();

    int array7[4][4] = {{0,1,1,1},
                        {1,1,1,1},
                        {0,0,1,0},
                        {1,0,0,1}};


    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(array7[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(7,v);


    v.clear();

    int array8[4][4] = {{0,1,1,0},
                        {1,0,0,1},
                        {0,0,0,0},
                        {1,0,0,1}};


    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(array8[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(8,v);

    v.clear();

    int array9[4][4] = {{1,1,0,0},
                        {1,1,0,0},
                        {1,0,0,0},
                        {1,1,0,1}};


    for(int i = 0; i < 4; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 4; j++)
        {
            v1.push_back(array9[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(9,v);


    int array10[5][5] = {{0,0,1,1,1},
                        {0,0,1,1,1},
                        {0,0,0,0,1},
                        {1,0,0,0,0},
                        {1,1,1,0,1}};

    v.clear();
    for(int i = 0; i < 5; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 5; j++)
        {
            v1.push_back(array10[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(10,v);

    int array11[5][5] = {{1,1,1,0,1},
                         {0,1,1,0,0},
                         {0,1,0,0,1},
                         {0,1,1,0,0},
                         {1,1,1,0,1}};

    v.clear();
    for(int i = 0; i < 5; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 5; j++)
        {
            v1.push_back(array11[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(11,v);

    int array12[5][5] = {{0,0,1,0,0},
                        {0,1,0,1,0},
                        {1,0,0,1,1},
                        {1,1,1,0,1},
                        {1,1,1,1,0}};

    v.clear();
    for(int i = 0; i < 5; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 5; j++)
        {
            v1.push_back(array12[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(12,v);

    int array13[6][6] = {{0,0,0,0,0,1},
                         {1,0,1,0,0,1},
                         {1,1,0,1,0,1},
                         {0,1,0,1,0,0},
                         {0,0,1,0,1,1}};

    v.clear();
    for(int i = 0; i < 6; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 6; j++)
        {
            v1.push_back(array13[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(13,v);

    int array14[6][6] = {{0,1,0,1,1,0},
                         {0,1,0,1,1,1},
                         {0,0,1,1,0,1},
                         {0,0,1,1,0,0},
                         {1,0,1,0,1,1}};

    v.clear();
    for(int i = 0; i < 6; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 6; j++)
        {
            v1.push_back(array14[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(14,v);

    int array15[6][6] = {{1,0,1,1,0,1},
                         {0,0,0,0,0,0},
                         {1,1,1,0,1,1},
                         {1,0,1,1,1,0},
                         {0,1,1,0,0,1}};

    v.clear();
    for(int i = 0; i < 6; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 6; j++)
        {
            v1.push_back(array15[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(15,v);

    int array16[6][6] = {{1,0,1,1,0,1},
                         {0,0,1,0,0,0},
                         {1,1,1,1,0,1},
                         {1,0,0,1,0,1},
                         {1,1,0,0,1,1}};

    v.clear();
    for(int i = 0; i < 6; i++)
    {
        QVector<int>v1;
        for(int j = 0; j < 6; j++)
        {
            v1.push_back(array16[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(16,v);


}
