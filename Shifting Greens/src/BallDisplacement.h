#pragma once

#include "Movel.h"

class BallDisplacement : public Movel {
public:
    BallDisplacement(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Run(float dt) override;
    void Render(SDL_Renderer* renderer) override;
    void HandleEvents(SDL_Event& event) override;
};
