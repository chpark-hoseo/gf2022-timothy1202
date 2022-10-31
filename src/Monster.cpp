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
    if (n_x ==0)
        n_x -= 1;
    else if (n_x == 1000)
        n_x += 1;
}