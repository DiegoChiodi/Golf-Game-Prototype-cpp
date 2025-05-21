#pragma once

#include "Movel.h"
#include "BallDisplacement.h" 

class Ball : public Movel {
protected:

    BallDisplacement* ballDisplacement = nullptr;
public:
    Ball(float x, float y, float width, float height, SDL_Color color, vector speed);
<<<<<<< HEAD
    void Run(const float& dt) override;
    void Render(SDL_Renderer* renderer) override;
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt) override;
=======
    void Run(float dt) override;
    void Render(SDL_Renderer* renderer) override;
    void HandleEvents(SDL_Event& event) override;
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
};