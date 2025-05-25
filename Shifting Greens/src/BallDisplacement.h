#pragma once

#include "Movel.h"

class BallDisplacement : public Movel {
public:
    BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;
};