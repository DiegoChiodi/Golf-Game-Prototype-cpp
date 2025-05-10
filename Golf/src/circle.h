#pragma once

#include "GameObject.h"

struct CircleFormat {
    float x, y, r;
};

class Circle : protected GameObject {
protected:
    SDL_Color color;
    CircleFormat format;
public:
    Circle(float x, float y, CollisionType collisionType, SDL_Color color, float r);
    void Render(SDL_Renderer* renderer) override;
    
};