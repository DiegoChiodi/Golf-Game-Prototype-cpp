#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color)
    : Square(x, y, width, height, color) {}
// ...existing code...

void Ball::Run(float dt) { // Recebe dt como parâmetro

    this->position.x += (100.0f * dt);

    rect.x = static_cast<int>(this->position.x);
    rect.y = static_cast<int>(this->position.y);
}
// ...existing code...