#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color)
    : Square(x, y, width, height, color) {}

void Ball::Run() {
    this->position.x += static_cast<float>(100.0f * dt); // Move the ball to the right 
    rect.x = static_cast<int>(this->position.x);
    rect.y = static_cast<int>(this->position.y);
}