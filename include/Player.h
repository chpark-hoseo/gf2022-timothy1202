#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    void handleInput();
    void CrashUp();
    void CrashDown();
    void CrashRight();
    void CrashLeft();
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void move();
    void start();
    static float Player_x;
    static float Player_y;
    float Before_Player_x;
    float Before_Player_y;
    //∞‘¿” ∏ 
    bool map[12][10] = { 1,1,1,1,1,1,1,1,1,1,1,1,
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
    int Player_Position_y=3;
};