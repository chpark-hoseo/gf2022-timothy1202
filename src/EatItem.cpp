#include"EatItem.h"
#include"Player.h"
#include<iostream>
#include"Play.h"
// 아이템

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

//아이템 다 먹으면 넘어가야하는데 하나만 먹어도 계속 올라가서 화면이 넘어감
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