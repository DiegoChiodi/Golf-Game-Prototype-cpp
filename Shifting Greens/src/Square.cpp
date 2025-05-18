#include "Square.h"

Square::Square(float x, float y, float width, float height, SDL_Color color)
    : GameObject(x, y, width, height), color(color), rect{static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height)}
{}


Square::~Square() {}

void Square::Run() {
    // Atualiza a posição do quadrado
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
}

void Square::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

bool Square::CheckCollision(point otherPosition, float otherWidth, float otherHeight) const {
    // Verifica se há colisão entre dois quadrados
    return (position.x < otherPosition.x + otherWidth &&
            position.x + rect.w > otherPosition.x &&
            position.y < otherPosition.y + otherHeight &&
            position.y + rect.h > otherPosition.y);
}