#pragma once
#include <SDL2/SDL.h> 
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"
#include <vector>

	
class Game 
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	/*Monster m_monster; 
	Monster m_monster2;*/
	std::vector<GameObject*> m_gameObjects;
	//std::vector<GameObject*> m_gameObjects1;
	//int i = 0;

private:
	int m_currentFrame;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	typedef struct SDL_Rect
	{
		int x, y;
		int w, h;
	}SDL_Rect;
};