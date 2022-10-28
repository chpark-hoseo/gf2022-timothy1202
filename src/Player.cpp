#include "Player.h"
#include <SDL2/SDL_image.h>

void Player::load(int x, int y, int width, int height, std::string textureID, int p_currentFrame)
{
    GameObject::load(x, y, width, height, textureID,p_currentFrame);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    p_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_x -= 1;
}