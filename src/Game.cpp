#pragma once
#include "Game.h"
#include<iostream>
#include <SDL2/SDL_image.h>
#include"LoaderParams.h"
#include"Enemy.h"
#include "InputHandler.h"


int dest = 0;
Game* g_game = 0;
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0); // 붉은색 배경
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

    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/helicopter.png", "monster", m_pRenderer))
    {
        return false;
    }
    { //오브젝트 생성
        if (!TheTextureManager::Instance()->load("Assets/MovingPacMan.png", "MainCh", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/OneHObstacle.png", "Wall1", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/OneObstacle.png", "Wall2", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/SquareObstacle.png", "SquareWall", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/OrangeGhost.png", "O_Ghost", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/Ball.png", "Item", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/TObstacle.png", "T_Wall", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/PinkGhost.png", "P_Ghost", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/BlueGhost.png", "B_Ghost", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/Portal1.png", "Portal", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/GhostChange.png", "CH_Ghost", m_pRenderer))
        {
            return false;
        }


        if (!TheTextureManager::Instance()->load("Assets/button.png", "Play", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/exit.png", "Exit", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/main.png", "Main", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/cityskyline.png", "Background", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/resume.png", "Resume", m_pRenderer))
        {
            return false;
        }

        if (!TheTextureManager::Instance()->load("Assets/PacManLogo.png", "Logo", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/Door2.png", "Door", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/GameOver.png", "gameover1", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/Level1.png", "level1", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/Level2.png", "level2", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/Level3.png", "level3", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/LevelBackground.png", "levelbackground", m_pRenderer))
        {
            return false;
        }
        if (!TheTextureManager::Instance()->load("Assets/Level2GameBackground.png", "level2background", m_pRenderer))
        {
            return false;
        }
    }

    // 오브젝트 그리는 코드
    {
        //게임시작 화면
        m_startGame.push_back(new Object(new LoaderParams(0, 0, 1200, 1000, "Background")));//배경
        m_startGame.push_back(new Play(new LoaderParams(400, 300, 400, 100, "Exit")));//exit버튼
        m_startGame.push_back(new Play(new LoaderParams(400, 500, 400, 100, "Play"))); //play버튼
        m_startGame.push_back(new Play(new LoaderParams(400, 100, 400, 202, "Logo"))); //팩맨표지

        //레벨 선택 화면
        m_stages.push_back(new Object(new LoaderParams(0, 0, 1200, 1000, "levelbackground")));//레벨선택창 배경
        m_stages.push_back(new Play(new LoaderParams(0, 200, 423, 185, "level1")));//레벨1 고르기
        m_stages.push_back(new Play(new LoaderParams(800, 200, 423, 185, "level2")));//레벨2 고르기
        m_stages.push_back(new Play(new LoaderParams(400, 600, 423, 185, "level3")));//레벨3 고르기

        //게임종료 화면
        m_endGame.push_back(new Object(new LoaderParams(0, 0, 1200, 1000, "gameover1")));//게임오버배경

        //레벨1 화면
        m_gameObjects.push_back(new Player(new LoaderParams(400, 200, 96, 96, "MainCh")));//팩맨
        m_gameObjects.push_back(new Enemy(new LoaderParams(100, 200, 74, 96, "O_Ghost")));//오렌지 고스트
        m_gameObjects.push_back(new Monster(new LoaderParams(100, 100, 70, 96, "P_Ghost")));//핑크고스트
        m_gameObjects.push_back(new GhostChange(new LoaderParams(100, 700, 70, 96, "CH_Ghost")));//체인지고스트

        m_gameObjects.push_back(new Object(new LoaderParams(0, 100, 92, 200, "Wall1")));//세로벽
        m_gameObjects.push_back(new Object(new LoaderParams(0, 300, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 500, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 700, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(1100, 100, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(1100, 300, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(1100, 500, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(1100, 700, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 0, 200, 92, "Wall2")));//가로벽
        m_gameObjects.push_back(new Object(new LoaderParams(200, 0, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(400, 0, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(600, 0, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(800, 0, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(1000, 0, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 900, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(200, 900, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(400, 900, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(600, 900, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(800, 900, 200, 92, "Wall2")));
        m_gameObjects.push_back(new Object(new LoaderParams(1000, 900, 200, 92, "Wall2")));

        //레벨2 화면
        m_stage2.push_back(new Object(new LoaderParams(0, 0, 1200, 1000, "level2background")));//배경


    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    if (Play::GamePlay == 0)
    {
        for (int i = 0; i != m_startGame.size(); i++)
        {
            m_startGame[i]->update();
        }
    }
    else if (Play::GamePlay == 2)
    {
        for (int i = 0; i != m_endGame.size(); i++)
        {
            m_endGame[i]->update();
        }
    }
    else if (Play::GamePlay == 3)
    {
        for (int i = 0; i != m_stages.size(); i++)
        {
            m_stages[i]->update();
        }
    }
    else if (Play::GamePlay == 1)
    {
        for (int i = 0; i != m_gameObjects.size(); i++)
        {
            m_gameObjects[i]->update();
        }
    }
    else if (Play::GamePlay == 4)
    {
        for (int i = 0; i != m_stage2.size(); i++)
        {
            m_stage2[i]->update();
        }
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    if (Play::GamePlay == 0)
    {
        for (int i = 0; i != m_startGame.size(); i++)
        {
            m_startGame[i]->draw();
        }
  
    }
    else if (Play::GamePlay == 2)
    {
        for (int i = 0; i != m_endGame.size(); i++)
        {
            m_endGame[i]->draw();
        }
    }
    else if (Play::GamePlay == 3)
    {
        for (int i = 0; i != m_stages.size(); i++)
        {
            m_stages[i]->draw();
        }
    }
    else if (Play::GamePlay == 1)
    {
        for (int i = 0; i != m_gameObjects.size(); i++) 
        {
            m_gameObjects[i]->draw();
        }
    }
    else if (Play::GamePlay == 4)
    {
        for (int i = 0; i != m_stage2.size(); i++)
        {
            m_stage2[i]->draw();
        }
    }

    SDL_RenderPresent(m_pRenderer);

}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
    TheInputHandler::Instance()->clean();
}

