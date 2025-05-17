#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_mixer.h>

enum class CollisionType {
    RECTANGLE,
    CIRCLE
};

struct vector {
    float x, y;
};

using point = struct vector;

class GameObject {
protected:
    float x, y;
    CollisionType collisionType;
public:
    GameObject(float x, float y, CollisionType collisionType);
    virtual ~GameObject();

    virtual void Run() = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

    float GetX() const { return x; }
    float GetY() const { return y; }
    CollisionType GetCollisionType() const { return collisionType; }
};