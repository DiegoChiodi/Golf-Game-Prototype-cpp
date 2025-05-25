#include "Square.h"

Square::Square(float x, float y, float width, float height, SDL_Color color)
    : GameObject(x, y, width, height), color(color), rect{static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height)}
{}


Square::~Square() {}

void Square::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) {
    // Atualiza a posição do retângulo com base na posição do objeto
    ActualizeRect();
    Render(renderer, camera);
}

void Square::Render(SDL_Renderer* renderer, const SDL_Rect& camera) {
    SDL_Rect renderRect;
    renderRect.x = this->rect.x - camera.x;
    renderRect.y = this->rect.y - camera.y;
    renderRect.w = this->rect.w;
    renderRect.h = this->rect.h;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &renderRect);
}

void Square::ActualizeRect() {
    // Atualiza a posição do retângulo com base na posição do objeto
    rect.w = static_cast<int>(width);
    rect.h = static_cast<int>(height);
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
}

bool Square::CheckCollision(point otherPosition, float otherWidth, float otherHeight) const {
    // Verifica se há colisão entre dois quadrados
    return (position.x < otherPosition.x + otherWidth &&
            position.x + rect.w > otherPosition.x &&
            position.y < otherPosition.y + otherHeight &&
            position.y + rect.h > otherPosition.y);
}