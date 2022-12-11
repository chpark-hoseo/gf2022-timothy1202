#pragma once
#include"SDLGameObject.h"

class EatItem : public SDLGameObject
{
public:
    EatItem(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    int BallDraw = 1;
}; 
