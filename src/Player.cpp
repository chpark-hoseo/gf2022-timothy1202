#include "Player.h"
#include <SDL2/SDL_image.h>


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::clean() {}

void Player::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_velocity.setX(1);
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
}