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
    else if (BallDraw == 0)
    {
        Player::AteItem++;
        std::cout << Player::AteItem << std::endl;
        BallDraw = 2;
    }
    else if (BallDraw == 2)
        return;
}

//������ �� ������ �Ѿ���ϴµ� �ϳ��� �Ծ ��� �ö󰡼� ȭ���� �Ѿ
void EatItem::update()
{
    if (((Player::Player_x <= m_position.getX() + 50) && (Player::Player_x + 100 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 50) && (Player::Player_y + 100 >= m_position.getY())))
    {
        if(BallDraw==1)
        BallDraw = 0;
    }
    SDLGameObject::update();
}

void EatItem::clean() {}