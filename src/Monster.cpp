#include"Monster.h"


Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Monster::draw()
{
    SDLGameObject::draw();
}

void Monster::update()
{
    SDLGameObject::update();
    m_velocity.setX(2);
    //m_x += 1;
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
}

void Monster::clean() {}