#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update(int speed);
    void clean() {};

private:
    bool way = 1;
    int speed = 1;
};