#include"GhostChange.h"
#include"Player.h"
#include<iostream>
#include"Play.h"
//체인지고스트

GhostChange::GhostChange(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void GhostChange::draw()
{
    SDLGameObject::draw();
}

void GhostChange::update()
{
    SDLGameObject::update();

    if (CH_Way == 1)
    {
        m_velocity.setX(2);
        if (m_position.getX() > 1000)
        {
            CH_Way = 2;
            m_velocity.setX(0);
        }
    }
 
    else if (CH_Way == 2)
    {
        m_velocity.setX(-2);
        if (m_position.getX() < 100)
        {
            CH_Way = 1;
            m_velocity.setX(0);
        }
    }
    if (((Player::Player_x <= m_position.getX() + 70) && (Player::Player_x + 96 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 96) && (Player::Player_y + 96 >= m_position.getY())))
    {
        Play::GamePlay = 2;
    }

}

void GhostChange::clean() {}