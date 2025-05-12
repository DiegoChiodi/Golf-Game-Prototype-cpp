#include "Circle.h"

Circle::Circle(float x, float y, CollisionType collisionType, SDL_Color color, float r)
    : GameObject(x, y, collisionType), color(color), format{ x, y, r}
    {}

void Circle::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização da bola
    filledCircleColor(renderer, x, y, 10, 0x0000FFFF);
}

void Circle::Run() {

}

bool Circle::CheckCollision(GameObject* other) {
    return false;   
}