#pragma once

#include "GameObject.h"

struct CircleFormat {
    float x, y, r;
};

class Circle : public GameObject {
protected:
    SDL_Color color;
    CircleFormat format;
public:
    Circle(float x, float y, CollisionType collisionType, SDL_Color color, float r);
    void Render(SDL_Renderer* renderer) override;
    void Run() override;
    bool CheckCollision(GameObject* other) override;
};