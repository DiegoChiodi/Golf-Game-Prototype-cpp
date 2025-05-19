#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color)
    : Square(x, y, width, height, color) {}

void Ball::Run(float dt) 
{ // Recebe dt como parâmetro
    this->position.x += (100.0f * dt);
    Square::ActualizeRect();
}