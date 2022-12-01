#pragma once
#include"SDLGameObject.h"

class Monster : public SDLGameObject
{
public:
    Monster(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    int Gh_Way = 1;
};