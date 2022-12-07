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
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
    SDLGameObject::update();
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(2);
        m_currentRow = 0;
        CrashRight();
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-2);
        m_currentRow = 1;
        CrashLeft();
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-2);
        m_currentRow = 2;
        CrashUp();
        std::cout<<m_position.getY();
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setY(2);
        m_currentRow = 3;
        CrashDown();
    }
}
//���ľ��� �浹 �ڵ� �̻���
void Player::CrashUp() //���� �ε���
{
    if (m_position.getY() < 100)
    {
        m_position.setY(101);
    }

    else if (m_position.getY() < 400 && (m_position.getX() > 200 && m_position.getX() < 400))
    {
        m_velocity.setY(2);
    }
}

void Player::CrashDown() //�Ʒ������� �ε���
{
     if (m_position.getY() > 800)
     {
         m_position.setY(799);
     }

     else if (m_position.getY() > 100 && (m_position.getX() > 200 && m_position.getX() < 400))
     {
         m_velocity.setY(-2);
     }
}

void Player::CrashRight() // ���������� �ε��� (��ǥ�� �������� �������� �˾ƾ���)
{
    if (m_position.getX() > 1000)
    {
        m_position.setX(999);
    }

    else if ((m_position.getY() > 100 && m_position.getY() < 400) && m_position.getX() > 100)
    {
        m_position.setX(99);
    }
}

void Player::CrashLeft() //�������� �ε���
{

    if (m_position.getX() < 100)
    {
        m_position.setX(101);
    }

    else if ((m_position.getY() > 100 && m_position.getY() < 400) && m_position.getX() < 400)
    {
        m_position.setX(401);
    }
}