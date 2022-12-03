#include "Object.h"
#include <SDL2/SDL_image.h>
#include"Player.h"

Object::Object(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Object::draw()
{
    SDLGameObject::draw();
}

void Object::clean() {}

void Object::update()
{
    SDLGameObject::update();
    //if (((Player::Player_x <= m_position.getX() + 92) && (Player::Player_x + 96 >= m_position.getX())) && ((Player::Player_y <= m_position.getY() + 200) && (Player::Player_y + 96 >= m_position.getY())))
    //{
    //  //  Player::m_velocity.setX(-2);
    //}
    //
}
