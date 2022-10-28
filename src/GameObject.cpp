#include "GameObject.h"
#include <SDL2/SDL_image.h>
#include "TextureManager.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID, int p_currentFrame)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    m_currentRow = 0;
    m_currentFrame = 0;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
    TheTextureManager::Instance()
        ->drawFrame(m_textureID,
            m_x, m_y,
            m_width, m_height,
            m_currentRow,
            m_currentFrame,
            pRenderer);
}

void GameObject::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % p_currentFrame);
    m_x += 1;
}