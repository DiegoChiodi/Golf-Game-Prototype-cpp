#include "Ball.h"

Ball::Ball(float x, float y, CollisionType collisionType, SDL_Color color, float r)
    : Circle(x, y, collisionType, color, r) {}

void Ball::Run() {
    this->x += 1.0f; // Mover a bola para a direita
}