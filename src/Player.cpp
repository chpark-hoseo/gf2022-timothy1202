#include "Player.h"
#include <SDL2/SDL_image.h>

void Player::load(int x, int y, int width, int height, std::string textureID, int m_currentFrame)
{
    GameObject::load(x, y, width, height, textureID,m_currentFrame);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    m_x -= 1;
}