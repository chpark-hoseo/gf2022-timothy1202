#include"EatItem.h"
#include"Player.h"
#include<iostream>
#include"Play.h"
// ������

EatItem::EatItem(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void EatItem::draw()
{
    if (BallDraw == 1)
        SDLGameObject::draw();
    else
        return;
}

//������ �� ������ �Ѿ���ϴµ� �ϳ��� �Ծ ��� �ö󰡼� ȭ���� �Ѿ
void EatItem::update()
{
    if (((Player::Player_x <= m_position.getX() + 50) && (Player::Player_x + 100 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 50) && (Player::Player_y + 100 >= m_position.getY())))
    {
        BallDraw = 0;
        std::cout << Player::AteItem << std::endl;
    }
   /* if (AteItem == 55)
    {
        Play::GamePlay = 4;
    }*/
    SDLGameObject::update();
}

void EatItem::clean() {}