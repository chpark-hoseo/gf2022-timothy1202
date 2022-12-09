#include"Monster.h"
#include"Player.h"
#include<iostream>
#include"Play.h"
//핑크몬스터

Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Monster::draw()
{
    SDLGameObject::draw();
}

void Monster::update()
{
    SDLGameObject::update();

    if (Gh_Way == 1)
    {
        m_velocity.setX(2);
        if (m_position.getX() > 1000)
        {
            Gh_Way = 2;
            m_velocity.setX(0);
        }
    }
    else if (Gh_Way == 2)
    {
        m_velocity.setY(2);
        if (m_position.getY() > 800)
        {
            Gh_Way = 3;
            m_velocity.setY(0);
        }
    }
    else if (Gh_Way == 3)
    {
        m_velocity.setY(-2);
        if (m_position.getY() < 100)
        {
            Gh_Way = 4;
            m_velocity.setY(0);
        }
    }
    else if (Gh_Way == 4)
    {
        m_velocity.setX(-2);
        if (m_position.getX() < 100)
        {
            Gh_Way = 1;
            m_velocity.setX(0);
        }
    }
 /*   if (((Player::Player_x <= m_position.getX() + 70) && (Player::Player_x + 96 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 96) && (Player::Player_y + 96 >= m_position.getY())))
    {
        Play::GamePlay = 2;
    }*/

}

void Monster::clean() {}