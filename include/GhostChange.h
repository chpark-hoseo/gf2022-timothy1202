#pragma once
#include"SDLGameObject.h"

class GhostChange : public SDLGameObject
{
public:
    GhostChange(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    //virtual void HandleInput();
    int CH_Way = 1;
};