#pragma once
#include"SDLGameObject.h"

class VWall : public SDLGameObject
{
public:
    VWall(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};