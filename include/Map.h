#pragma once

class Map
{
private:
    static Map* s_pInstance;
public:
    void map();
    void update();
    int map1[12][10] = { 1,1,1,1,1,1,1,1,1,1,1,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,1,
                        1,1,1,1,1,1,1,1,1,1,1,1 };
    int x[12][10] = { 0, };
    int y[12][10] = { 0, };
    static Map* Instance()
    {
        if (s_pInstance == 0)
            s_pInstance = new Map();
        return s_pInstance;
    }


};
typedef Map TheMap;