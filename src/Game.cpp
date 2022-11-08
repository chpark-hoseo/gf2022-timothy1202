#pragma once
#include "Game.h"
#include<iostream>
#include <SDL2/SDL_image.h>

int dest = 0;
Game* Game::s_pInstance = 0;
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); // 붉은색 배경
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


    GameObject* m_go = new GameObject();
    GameObject* m_player = new Player();
    GameObject* m_monster = new Monster();

    m_go->load(100, 100, 128, 82, "animate");
    m_player->load(300, 300, 128, 82, "animate");
    m_monster->load(400, 400, 128, 55, "monster");

    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_monster);

    m_bRunning = true;
    return true;
}

void Game::update()
{
    //for(std::vector<GameObject*> m_gameObjects1 : m_gameObjects[i])
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(m_pRenderer);
    }
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
    SDL_Quit();
}

