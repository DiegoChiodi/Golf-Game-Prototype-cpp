#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright)
    : Movel(x, y, width, height, color, speed), textureUpright(textureUpright) {
        actualTexture = textureUpright;
    }

void Player::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) {
    ActualizeRect();
    HandleEvents(stat, dt);
    Render(renderer);
    Animated(dt);
}

void Player::HandleEvents(const Uint8* stat, const float& dt) {
    isMoving = false;

    if (stat[SDL_SCANCODE_W]) {
        if (position.y - speed.y * dt >= 0) {
            position.y -= speed.y * dt;
        } else {
            position.y = 0;
        }
        currentDirection = Direction::UP;
        isMoving = true;
    }
        
    if (stat[SDL_SCANCODE_S]) {
        if (position.y + speed.y * dt + height <= heightJan) {
            position.y += speed.y * dt;
        } else {
            position.y = heightJan - height;
        }
        currentDirection = Direction::DOWN;
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

void Player::Animated(const float& dt) {
    if (this->isMoving) {

        if (animate)
        {
            std::cout << "Les" << std::endl;
        } else {
            std::cout << "go" << std::endl;
        }

        if (delayAnimate > 0.5f)
        {
            delayAnimate = 0.0f;
            animate = !animate;
        }
        delayAnimate += 0.05f;
    } else {
        this->actualTexture = this->textureUpright;
        delayAnimate = 0.0f;
    }
}

void Player::Render(SDL_Renderer* renderer) {
    
    if (this->currentDirection == Direction::LEFT && this->isMoving) {
        this->flip = SDL_FLIP_HORIZONTAL;
    } else if (this->currentDirection == Direction::RIGHT && this->isMoving) {
        this->flip = SDL_FLIP_NONE;
    }
    SDL_RenderCopyEx(renderer, actualTexture, nullptr, &rect, 0.0, nullptr, flip);
}