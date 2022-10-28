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
    if (m_x ==0)
        m_x -= 1;
    else if (m_x == 1000)
        m_x += 1;
}