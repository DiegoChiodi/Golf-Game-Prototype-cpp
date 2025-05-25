#include "Movel.h"

Movel::Movel(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Square(x, y, width, height, color), speed(speed){}

void Movel::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) {
    Square::Run(dt, stat, renderer);
    HandleEvents(stat, dt);
}
void Movel::HandleEvents(const Uint8* stat, const float& dt) {
    isMoving = false;

    if (stat[SDL_SCANCODE_W]) {
        if (position.y - speed.y * dt >= 0) {
            position.y -= speed.y * dt;
        } else {
            position.y = 0;
        }
        isMoving = true;
    }
        
    if (stat[SDL_SCANCODE_S]) {
        if (position.y + speed.y * dt + height <= heightJan) {
            position.y += speed.y * dt;
        } else {
            position.y = heightJan - height;
        }
        isMoving = true;
    }

    if (stat[SDL_SCANCODE_A]) {
        if (position.x - speed.x * dt >= 0) {
            position.x -= speed.x * dt;
        } else {
            position.x = 0;
        }
        currentDirection = Direction::LEFT;
        isMoving = true;
    }

    if (stat[SDL_SCANCODE_D]) {
        if (position.x + speed.x * dt + width <= widthJan) {
            position.x += speed.x * dt;
        } else {
            position.x = widthJan - width;
        }
        currentDirection = Direction::RIGHT;
        isMoving = true;
    }
}