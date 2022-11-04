#pragma once
#include <SDL2/SDL.h>
#include <string>

class GameObject {

public:
	virtual  void load(int x, int y, int width, int height,
		std::string textureID);
	virtual  void draw(SDL_Renderer* pRenderer);
	virtual  void update();
	virtual  void clean() {};

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;
};
