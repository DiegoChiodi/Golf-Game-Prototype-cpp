#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
    : position{x, y}, width(width), height(height) { }

void GameObject::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) {
    // Implementar lógica de atualização do objeto
}
void GameObject::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização do objeto
}

void GameObject::HandleEvents(const Uint8* stat, const float& dt) {
    // Implementar lógica de tratamento de eventos
}

GameObject::~GameObject() {}