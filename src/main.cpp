#include "Game.h"
#include<iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Game* g_game = 0;
    Uint32 frameStart, frameTime;
    while (TheGame::Instance()->running()) {
        frameStart = SDL_GetTicks();     // step 1
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        frameTime = SDL_GetTicks() - frameStart;  // step 2
        if (frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime)); // step 3
        }
    }

    TheGame::Instance()->clean();
    return 0;
}

