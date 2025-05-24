#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright)
    : Movel(x, y, width, height, color, speed), textureUpright(textureUpright) {
    }

void Player::Run(const float& dt) {
    // Atualiza a posição do retângulo com base na posição do objeto
    ActualizeRect();
}

void Player::HandleEvents(SDL_Event& event, const Uint8* stat, const float& dt) {
    if (stat[SDL_SCANCODE_W]) {
        if (position.y - speed.y * dt >= 0) {
            position.y -= speed.y * dt;
        } else {
            position.y = 0;
        }
    }
    if (stat[SDL_SCANCODE_S]) {
        if (position.y + speed.y * dt + height <= heightJan) {
            position.y += speed.y * dt;
        } else {
            position.y = heightJan - height;
        }
    }
    if (stat[SDL_SCANCODE_A]) {
        if (position.x - speed.x * dt >= 0) {
            position.x -= speed.x * dt;
        } else {
            position.x = 0;
        }
    }
    if (stat[SDL_SCANCODE_D]) {
        if (position.x + speed.x * dt + width <= widthJan) {
            position.x += speed.x * dt;
        } else {
            position.x = widthJan - width;
        }
    }
}

void Player::Render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, textureUpright, nullptr, &rect);
}