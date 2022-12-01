#include"Play.h"
#include"InputHandler.h"
#include<iostream>


//플레이버튼

int Play::GamePlay=0;

Play::Play(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Play::draw()
{
    SDLGameObject::draw();
}

void Play::update()
{
	HandleInput();
    SDLGameObject::update();
    m_currentFrame = ((SDL_GetTicks() / 100) % 3);
}

void Play::clean() {}

void Play::HandleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	std::cout << vec->getX();
	if ((vec->getX()>400 && vec->getX() <800)&&vec->getY() > 500)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			GamePlay = 1;
			std::cout << "GamePlay=1";
		}
	}
	else if ((vec->getX() > 400 && vec->getX() < 800) && vec->getY() < 400)
	{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		Play::GamePlay = 2;
		std::cout << "GamePlay=2";
	}

	}

}