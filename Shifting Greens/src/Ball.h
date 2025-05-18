#pragma once

#include "Square.h"

class Ball : public Square {
public:
    Ball(float x, float y, float width, float height, SDL_Color color);
    void Run(float dt) override;
};