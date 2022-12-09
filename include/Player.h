#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    void handleInput();
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void move();
    static float Player_x;
    static float Player_y;
    //∞‘¿” ∏ [y√‡][x√‡]
    bool map[10][12] = { 1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,1,1,0,0,0,0,0,0,0,1,
                         1,0,1,1,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,
                         1,1,1,1,1,1,1,1,1,1,1,1 };
private:
    int Player_Position_x=4;
    int Player_Position_y=2;
    float Before_Player_x = 400;
    float Before_Player_y = 200;
    void CheckPosition();
    bool MoveNow=1;
};