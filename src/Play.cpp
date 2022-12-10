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
	if(GamePlay==0)
    m_currentFrame = ((SDL_GetTicks() / 100) % 3);

}

void Play::clean() {}

void Play::HandleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (GamePlay == 0)
	{
		if ((vec->getX() > 400 && vec->getX() < 800) && (vec->getY() > 500 && vec->getY() < 600))
		{

			if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
				GamePlay = 3;
				std::cout << "GamePlay=3";
			}
		}
		else if ((vec->getX() > 400 && vec->getX() < 800) && (vec->getY() < 400 && vec->getY() > 300))
		{
				if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
					GamePlay = 2;
					std::cout << "GamePlay=2";
				}
		}
	}
	else if (GamePlay == 3)
	{
		if ((vec->getX() > 0 && vec->getX() < 423) && (vec->getY() < 385&& vec->getY() >200))
		{
				if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
					GamePlay = 1;
					std::cout << "GamePlay=1";
				}
		}

		if ((vec->getX() > 800 && vec->getX() < 1223) && (vec->getY() > 200 && vec->getY()<385))
		{
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
				GamePlay = 4;
				std::cout << "GamePlay=4";
			}
		}
	}
}