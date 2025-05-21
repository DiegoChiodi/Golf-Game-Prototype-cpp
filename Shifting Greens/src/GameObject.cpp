#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
    : position{x, y}, width(width), height(height) { }

void GameObject::Run(const float& dt) {
    // Implementar lógica de atualização do objeto
}
void GameObject::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização do objeto
}

GameObject::~GameObject() {}