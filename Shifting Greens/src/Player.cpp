#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright, SDL_Texture* textureSprinting)
    : Movel(x, y, width, height, color, speed), textureUpright(textureUpright), textureSprinting(textureSprinting), delayAnimate(0.0f) {
        actualTexture = textureUpright;
        isMoving = false;
        currentDirection = Direction::RIGHT;
    }

void Player::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) {
    Movel::Run(dt, stat, renderer);
    Animated(dt);
} 

void Player::Animated(const float& dt) {
    if (this->isMoving) {

        if (animate)
        {
            actualTexture = this->textureSprinting;
        } else {
            actualTexture = this->textureUpright;
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