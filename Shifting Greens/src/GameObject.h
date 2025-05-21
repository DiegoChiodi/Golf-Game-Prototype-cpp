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

<<<<<<< HEAD
    virtual void Run(const float& dt) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
    virtual void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt) = 0;
=======
    virtual void Run(float dt) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
    virtual void HandleEvents(SDL_Event& event) = 0;
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c

    point GetPosition() const { return position; }
};