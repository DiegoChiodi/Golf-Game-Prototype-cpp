#pragma once

#include "GlobalVariables.h"

#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_mixer.h>

struct vector {
    float x, y;
};

using point = struct vector;

class GameObject {
protected:
    point position;
    float width, height;
public:
    GameObject(float x, float y, float width, float height);
    virtual ~GameObject();

    virtual void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
    virtual void HandleEvents(const Uint8* stat, const float& dt) = 0;

    point GetPosition() const { return position; }
};