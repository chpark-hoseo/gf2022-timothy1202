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
};