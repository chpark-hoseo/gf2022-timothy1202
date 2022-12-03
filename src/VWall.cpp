//¼¼·Î º®
#include "VWall.h"
#include <SDL2/SDL_image.h>
#include"Player.h"

VWall::VWall(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void VWall::draw()
{
    SDLGameObject::draw();
}

void VWall::clean() {}

void VWall::update()
{
    SDLGameObject::update();
    if (((Player::Player_x <= m_position.getX() + 92) && (Player::Player_x + 96 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 200) && (Player::Player_y + 96 >= m_position.getY())))
    {
        Player::Player_x -= 2;
    }
    
}
