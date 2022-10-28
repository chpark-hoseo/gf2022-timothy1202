#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID, int m_currentFrame);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean() {};
};
