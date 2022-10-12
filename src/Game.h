#pragma once
#include <SDL2/SDL.h> 

class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void Jump();

	int JumpSpeed = -60;
	bool NowJump = 0;
	int x_move =1;

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	SDL_Texture* m_pTexture;

	// 원본 사각형
	SDL_Rect  m_sourceRectangle;

	// 대상 사각형
	SDL_Rect m_destinationRectangle;

	SDL_Texture* q_pTexture;

	// 원본 사각형
	SDL_Rect q_sourceRectangle;

	// 대상 사각형
	SDL_Rect q_destinationRectangle;

	typedef struct SDL_Rect
	{
		int x, y;
		int w, h;
	}SDL_Rect;
};