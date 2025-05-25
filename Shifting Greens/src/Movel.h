#pragma once

#include "Square.h"

class Movel : public Square {
protected:
    vector speed;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    bool isMoving;
    enum class Direction { RIGHT, LEFT };
    Direction currentDirection = Direction::RIGHT;
public:
    Movel(float x, float y, float width, float height, SDL_Color color, vector speed);

    virtual void HandleEvents(const Uint8* stat, const float& dt);
    virtual void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera);
};