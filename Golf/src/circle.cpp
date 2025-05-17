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

bool Circle::CheckCollisionCircle(const CircleFormat& other) { 
    //[(x2−x1)² + (y2−y1)²] <= (Raio1 + Raio2)
    float dx = other.x - this->x;
    float dy = other.y - this->y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = this->format.r + other.r;

    return distanceSquared <= (radiusSum);
}