#pragma once

#include "Movel.h"
#include "BallDisplacement.h" 

class Ball : public Movel {
protected:

    BallDisplacement* ballDisplacement = nullptr;
public:
    Ball(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Run(const float& dt) override;
    void Render(SDL_Renderer* renderer) override;
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt) override;
};