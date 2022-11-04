#include "Monster.h"
#include <SDL2/SDL_image.h>

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Monster::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    if (way == 1)
    {
        m_x += 1;
        if (m_x > 500)
            way = 0;
    }
    else if (way == 0)
    {
        m_x -=1;
        if (m_x < 100)
            way = 1;
    }

}