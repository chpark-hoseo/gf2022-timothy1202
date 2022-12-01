#include "Object.h"
#include <SDL2/SDL_image.h>

Object::Object(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Object::draw()
{
    SDLGameObject::draw();
}

void Object::clean() {}

void Object::update()
{
    SDLGameObject::update();
}
