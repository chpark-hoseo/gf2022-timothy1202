#include "Game.h"
#include<iostream>

int dest = 0;
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 255, 255, 255, 255);
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

        SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);

        SDL_QueryTexture(m_pTexture, NULL, NULL,
        &m_sourceRectangle.w, &m_sourceRectangle.h);

        m_destinationRectangle.w = m_sourceRectangle.w;
        m_destinationRectangle.h = m_sourceRectangle.h;
       // m_sourceRectangle.w= 640;
        //m_sourceRectangle.h= 480;
        m_destinationRectangle.w = 640;
        m_destinationRectangle.h = 480;

        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
        //m_destinationRectangle.x = 50;
        //m_destinationRectangle.y = 50;
        //m_sourceRectangle.x = 50;
        //m_sourceRectangle.y = 45;
        
        std::cout << "rider.bmp의 w/h: " << m_sourceRectangle.w <<"/"<<m_sourceRectangle.h;

   
        //m_destinationRectangle.x += 1;
        //SDL_Delay(5);
    m_bRunning = true;
    return true;
}

void Game::update()
{
    // 게임 데이터 갱신 
    //이미지 이동 코드
    /*if (dest == 1)
        m_destinationRectangle.x -= 1;
    else m_destinationRectangle.x += 1;
    SDL_Delay(5);
    if (m_destinationRectangle.x == 517)
        dest = 1;
    if (m_destinationRectangle.x == 0)
        dest = 0;*/
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    //SDL_RenderCopy(m_pRenderer, q_pTexture, &q_sourceRectangle, &q_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyTexture(m_pTexture); //Texture 파괴
    SDL_DestroyTexture(q_pTexture); //Texture 파괴
    SDL_Quit();
}

