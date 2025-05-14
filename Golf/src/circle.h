#pragma once

#include "GameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

struct CircleFormat {
    float x, y, r;
};

class Circle : public GameObject {
protected:
    SDL_Color color;
    CircleFormat format;
public:
    Circle(float x, float y, CollisionType collisionType, SDL_Color color, float r);
    int Render(SDL_Renderer* renderer) override;
    void Run() override;
    bool CheckCollision(GameObject* other) override;
};