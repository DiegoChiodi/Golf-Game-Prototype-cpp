#include "GameObject.h"

GameObject::GameObject(float x, float y, CollisionType collisionType)
    : x(x), y(y), collisionType(collisionType)
{}

void GameObject::Render(SDL_Renderer* renderer) {
    // Implementar lógica de renderização do objeto
}
GameObject::~GameObject() {}