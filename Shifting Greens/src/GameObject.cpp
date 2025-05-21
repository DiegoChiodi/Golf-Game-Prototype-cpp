#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
    : position{x, y}, width(width), height(height) {}

<<<<<<< HEAD
void GameObject::Run(const float& dt) {
=======
void GameObject::Run(float dt) {
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
    // Implementar lógica de atualização do objeto
}
void GameObject::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização do objeto
}

GameObject::~GameObject() {}