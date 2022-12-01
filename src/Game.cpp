#pragma once
#include "Game.h"
#include<iostream>
#include <SDL2/SDL_image.h>
#include"LoaderParams.h"
#include"Enemy.h"
#include "InputHandler.h"

bool Map[10][10] = { 1,1,1,1,1,1,1,1,1,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,1,
                     1,1,1,1,1,1,1,1,1,1};

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

        if (!TheTextureManager::Instance()->load("Assets/gameover.png", "Gameover", m_pRenderer))
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
    }

    // 오브젝트 그리는 코드
    {
        m_gameObjects.push_back(new Player(new LoaderParams(400, 100, 96, 96, "MainCh")));//팩맨
        m_gameObjects.push_back(new Enemy(new LoaderParams(200, 200, 128, 82, "animate")));
        m_gameObjects.push_back(new Monster(new LoaderParams(100, 100, 70, 96, "P_Ghost")));//핑크고스트
        m_gameObjects.push_back(new Object(new LoaderParams(0, 100, 92, 200, "Wall1")));//세로벽
        m_gameObjects.push_back(new Object(new LoaderParams(0, 300, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 500, 92, 200, "Wall1")));
        m_gameObjects.push_back(new Object(new LoaderParams(0, 700, 92, 200, "Wall1")));
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

    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for (int i = 0; i != m_gameObjects.size(); i++) 
    {
        m_gameObjects[i]->draw();
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

