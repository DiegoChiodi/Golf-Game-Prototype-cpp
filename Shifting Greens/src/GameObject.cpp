#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
    : position{x, y}, width(width), height(height) { }

void GameObject::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) {
    // Implementar lógica de atualização do objeto
}
void GameObject::Render(SDL_Renderer* renderer, const SDL_Rect& camera) {
    // Implementar lógica de renderização do objeto
}

void GameObject::SetPosition(vector pos) {
    position.x = pos.x;
    position.y = pos.y;
}

GameObject::~GameObject() {}