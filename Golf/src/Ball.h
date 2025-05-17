#pragma once

#include "Circle.h"
#include <memory>
#include <list>

class Ball : public Circle {
public:
    Ball(float x, float y, CollisionType collisionType, SDL_Color color, float r);
    void Run() override;
};