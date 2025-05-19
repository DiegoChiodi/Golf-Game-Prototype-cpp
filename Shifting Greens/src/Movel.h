#pragma once

#include "Square.h"

class Movel : public Square {
private:
    vector speed;
public:
    Movel(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Run(float dt) override;
    virtual void HandleEvents(SDL_Event& event);
};