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
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	Game() {}
	static Game* s_pInstance;
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
typedef Game TheGame;