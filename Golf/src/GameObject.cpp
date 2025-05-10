#include "GameObject.h"

GameObject::GameObject(float x, float y, CollisionType collisionType)
    : x(x), y(y), collisionType(collisionType)
{}

GameObject::~GameObject() {}