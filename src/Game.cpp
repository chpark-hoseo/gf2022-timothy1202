#include "Game.h"
#include<iostream>
#include <SDL2/SDL_image.h>

bool Way = 0;
int move_x = 0;
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); // 붉은색 배경
                //SDL_SetRenderDrawColor(
                  //  m_pRenderer, 255, 255, 255, 255);
            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생설 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }
    m_textureManager.load("Assets/Gioo.png", "animate", m_pRenderer);

        // 배경 표출 코드
        /*SDL_Surface* pTempSurface1 = SDL_LoadBMP("Assets/Background.bmp");
        q_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface1);
        SDL_FreeSurface(pTempSurface1);

        SDL_QueryTexture(q_pTexture, NULL, NULL,
            &q_sourceRectangle.w, &q_sourceRectangle.h);

        q_destinationRectangle.w = q_sourceRectangle.w;
        q_destinationRectangle.h = q_sourceRectangle.h;

        q_destinationRectangle.x = q_sourceRectangle.x = 0;
        q_destinationRectangle.y = q_sourceRectangle.y = 0;
        */

        

    m_bRunning = true;
    return true;
}

void Game::update()
{
    // 게임 데이터 갱신 
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_LEFT])

    {
        Way = 1;
        move_x -=1;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        SDL_Delay(3);
    }

    else if (currentKeyStates[SDL_SCANCODE_RIGHT])

    {
        Way = 0;
        move_x += 1;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        SDL_Delay(3);
    }

   /* else
    {
        srcRect.x = 0;
    }*/
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    //m_textureManager.draw("animate", 0, 0, 65.8, 66, m_pRenderer);
    if( Way ==1 )
    m_textureManager.drawFrame("animate", move_x=100, 100, 65.8, 66, 0, m_currentFrame, m_pRenderer);
    else if (Way==0)
    m_textureManager.drawFrame("animate", move_x =100, 100, 65.8, 66, 1, m_currentFrame, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    //SDL_DestroyWindow(m_pWindow);
    //SDL_DestroyRenderer(m_pRenderer);
    //SDL_DestroyTexture(m_pTexture); //Texture 파괴
    //SDL_DestroyTexture(q_pTexture); //Texture 파괴
    SDL_Quit();
}

