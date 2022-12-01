#include "Player.h"
#include <SDL2/SDL_image.h>
#include "InputHandler.h"

float Player::Player_x;
float Player::Player_y;
bool Player::Block;
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
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
    SDLGameObject::update();
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        if (Block == 1)
        {
            m_velocity.setX(0);
        }
        else if(Block == 0)
           m_velocity.setX(2);
        m_currentRow = 0;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        if (Block == 1)
        {
            m_velocity.setX(0);
        }
        else if (Block == 0)
        m_velocity.setX(-2);
        m_currentRow = 1;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        if (Block == 1)
        {
            m_velocity.setY(0);
        }
        else if (Block == 0)
        m_velocity.setY(-2);
        m_currentRow = 2;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        if (Block == 1)
        {
            m_velocity.setY(0);
        }
        else if (Block == 0)
        m_velocity.setY(2);
        m_currentRow = 3;
    }
}