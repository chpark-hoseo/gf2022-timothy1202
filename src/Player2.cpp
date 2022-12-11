#include "Player2.h"
#include <SDL2/SDL_image.h>
#include "InputHandler.h"
#include"iostream"


float Player2::Player2_x;
float Player2::Player2_y;
int Player2::AteItem2 = 0;
Player2::Player2(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player2::draw()
{
    SDLGameObject::draw();
}

void Player2::clean() {}

void Player2::update()
{
    Player2_x = m_position.getX();
    Player2_y = m_position.getY();
    move();
    CheckPosition2();
    handleInput2();
    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
    SDLGameObject::update();
}

void Player2::move()
{
    //�迭 ���������� ��ĭ
    if (Before_Player2_x + 100 == m_position.getX())
    {
        Player2_Position_x++;
        Before_Player2_x = m_position.getX();
        std::cout << Player2_Position_x << std::endl;
        std::cout << Before_Player2_x << std::endl;
    }
    //�迭 �Ʒ��� ��ĭ
    else if (Before_Player2_y + 100 == m_position.getY()) {
        Player2_Position_y++;
        Before_Player2_y = m_position.getY();
        std::cout << Player2_Position_y << std::endl;
        std::cout << Before_Player2_y << std::endl;
    }
    //�迭 �������� ��ĭ
    else if (Before_Player2_x - 100 == m_position.getX())
    {
        Player2_Position_x--;
        Before_Player2_x = m_position.getX();
        std::cout << Player2_Position_x << std::endl;
        std::cout << Before_Player2_x << std::endl;
    }
    //�迭 ���� ��ĭ
    else if (Before_Player2_y - 100 == m_position.getY()) {
        Player2_Position_y--;
        Before_Player2_y = m_position.getY();
        std::cout << Player2_Position_y << std::endl;
        std::cout << Before_Player2_y << std::endl;
    }
}

void Player2::CheckPosition2()
{
    //������
    if (map2[Player2_Position_y][Player2_Position_x + 1] == 1)
    {
        if (m_velocity.getX() > 0)
            m_velocity.setX(0);
    }
    //�Ʒ�
    if (map2[Player2_Position_y + 1][Player2_Position_x] == 1)
    {
        if (m_velocity.getY() > 0)
            m_velocity.setY(0);
    }
    //����
    if (map2[Player2_Position_y - 1][Player2_Position_x] == 1)
    {
        if (m_velocity.getY() < 0)
            m_velocity.setY(0);
    }
    //����
    if (map2[Player2_Position_y][Player2_Position_x - 1] == 1)
    {
        if (m_velocity.getX() < 0)
            m_velocity.setX(0);
    }
}

void Player2::handleInput2()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {

        m_velocity.setY(0);
        m_currentRow = 0;
        m_velocity.setX(2);
    }


    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {

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