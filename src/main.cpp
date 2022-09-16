#include <SDL2/SDL.h>
#include<stdlib.h>
#include<time.h>


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false; // 값이 제대로 들어가면 창을 실행시키고 값이 잘못되었으면 무한루프

bool init(const char* title, int xpos, int ypos, int height, int width, int flags) //윈도우 / 랜더러 생성 및 초기화
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

        g_pWindow = SDL_CreateWindow(
            title, xpos, ypos, height, width, flags);

        if (g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }

    }
    else {
        return false;
    }

    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    return true;
}

void render()
{
    SDL_RenderClear(g_pRenderer);

    // 그리기 수행  

    SDL_RenderPresent(g_pRenderer);
}

void update()
{
    SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);
}

int main(int argc, char* argv[])
{
    if (init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480,
        SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1; // something's wrong
    }
     
    while (g_bRunning)
    {
        // handle input - update - render
        update();
        render();
    }
    
    SDL_Quit();
    return 0;
}