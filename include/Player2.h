#pragma once
#include "SDLGameObject.h"

class Player2 : public SDLGameObject
{
public:
    void handleInput2();
    static int AteItem2;
    Player2(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void move();
    static float Player2_x;
    static float Player2_y;
    //∞‘¿” ∏ [y√‡][x√‡]
    bool map2[10][12] = { 1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,1,1,0,1,1,0,1,1,0,1,
                         1,0,1,1,0,0,0,0,0,0,0,1,
                         1,0,0,0,1,0,1,1,0,1,1,1,
                         1,0,1,0,1,0,1,1,0,0,0,1,
                         1,0,1,0,0,0,0,0,0,1,0,1,
                         1,0,1,1,0,1,1,1,0,1,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,1,1,1,1,1,1,1,1,1,1,1 };
private:
    int Player2_Position_x = 4;
    int Player2_Position_y = 2;
    float Before_Player2_x = 400;
    float Before_Player2_y = 200;
    void CheckPosition2();
};