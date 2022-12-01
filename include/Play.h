#pragma once
#include"SDLGameObject.h"



class Play : public SDLGameObject
{
public:
    Play(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    static int GamePlay;
    virtual void HandleInput();
};
