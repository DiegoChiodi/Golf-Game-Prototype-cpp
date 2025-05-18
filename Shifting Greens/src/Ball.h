#pragma once

#include "Square.h"
#include <memory>
#include <list>

class Ball : public Square {
public:
    Ball(float x, float y, float width, float height, SDL_Color color);
    void Run() override;
};