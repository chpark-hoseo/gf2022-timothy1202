#include"SDLGameObject.h"
#include"TextureManager.h"
#include"LoaderParams.h"
#include"Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
    : GameObject(pParams) {
    m_x = pParams->getX();
    m_y = pParams->getY();
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 0;
    m_currentFrame = 0;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(m_textureID,
        m_x, m_y, m_width,
        m_height, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer());
}