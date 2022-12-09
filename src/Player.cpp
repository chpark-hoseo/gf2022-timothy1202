#include "Player.h"
#include <SDL2/SDL_image.h>
#include "InputHandler.h"
#include"iostream"


float Player::Player_x;
float Player::Player_y;
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::clean() {}

void Player::update()
{
    Player_x = m_position.getX();
    Player_y = m_position.getY();
    CheckPosition();
    move();
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
    SDLGameObject::update();
}

void Player::move()
{
    if (Before_Player_x +100 == m_position.getX())
    {
        Player_Position_x++;
        Before_Player_x = m_position.getX();
        std::cout << Player_Position_x << std::endl;
        std::cout << Before_Player_x << std::endl;
    }
    else if (Before_Player_y +100 == m_position.getY()) {
        Player_Position_y++;
        Before_Player_y= m_position.getY();
    }
}

void Player::CheckPosition()
{
    //¿À¸¥ÂÊ
          if (map[Player_Position_y][Player_Position_x + 1] == 1)
          {
              MoveNow = 0;
              if (MoveNow == 1)
                  return;
              else
              m_velocity.setX(0);
          }
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        MoveNow = 1;
        m_velocity.setY(0);
        m_currentRow = 0;
        m_velocity.setX(2);
    }


    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        MoveNow = 1;
        m_velocity.setY(0);
        m_velocity.setX(-2);
        m_currentRow = 1;

    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setX(0);
        m_velocity.setY(-2);
        m_currentRow = 2;

    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setX(0);
        m_velocity.setY(2);
        m_currentRow = 3;

    }
}