#include"Enemy.h"
#include "Play.h"
#include "Player.h"
#include<iostream>

//오렌지고스트

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::clean() {}

void Enemy::update()
{
	//HandleInput();
	//m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	SDLGameObject::update();
	//m_acceleration.setX(1);
	
	if (OG_Way == 1)
	{
		m_velocity.setY(2);
		if (m_position.getY() > 800)
		{
			OG_Way = 2;
			m_velocity.setY(0);
		}
	}
	else if (OG_Way == 2)
	{
		m_velocity.setY(-2);
		if (m_position.getY() < 100)
		{
			OG_Way = 1;
			m_velocity.setY(0);
		}
	}
	if (((Player::Player_x <= m_position.getX() + 70) && (Player::Player_x + 96 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 96) && (Player::Player_y + 96 >= m_position.getY())))
	{
		Play::GamePlay = 2;
	}
}

//void Enemy::HandleInput()
//{
//	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
//		printf("shoot \n");
//	}
//	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
//	m_velocity = (*vec - m_position) / 100;
//
//}