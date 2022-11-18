#include"Enemy.h"
#include"LoaderParams.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::clean() {}

void Enemy::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	m_acceleration.setX(1);
}