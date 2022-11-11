#include"Monster.h"

Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Monster::draw()
{
    SDLGameObject::draw();
}

void Monster::update()
{
    m_y += 1;
    m_x += 1;
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Monster::clean() {}