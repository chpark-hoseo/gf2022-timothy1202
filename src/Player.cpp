#include "Player.h"
#include <SDL2/SDL_image.h>


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::update()
{
    m_x -= 1;
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::clean() {}