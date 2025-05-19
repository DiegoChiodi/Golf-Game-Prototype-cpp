#pragma once

#include "Movel.h"

class Ball : public Movel {
public:
    Ball(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Run(float dt) override;
    void Render(SDL_Renderer* renderer) override;
};