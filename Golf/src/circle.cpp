#include "Circle.h"

Circle::Circle(float x, float y, CollisionType collisionType, SDL_Color color, float r)
    : GameObject(x, y, collisionType), color(color), format{ x, y, r}
    {}

void Circle::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização da bola
    filledCircleRGBA(renderer, x, y, 10, color.r, color.g, color.b, color.a);
}

void Circle::Run() {

}

bool Circle::CheckCollision(GameObject* other) {
    return false;   
}