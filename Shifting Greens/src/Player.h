#pragma once

#include "Movel.h"
#include <SDL2/SDL_image.h>


class Player : public Movel {
private:
    SDL_Texture* actualTexture;
    SDL_Texture* textureUpright;
    SDL_Texture* textureSprinting;
    bool isMoving;
    enum class Direction { RIGHT, LEFT};
    Direction currentDirection;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    bool animate = false;
    float delayAnimate = 0.1f;
public:
    Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright, SDL_Texture* textureSprinting);
    void Render(SDL_Renderer* renderer) override;
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) override;
    void HandleEvents(const Uint8* stat, const float& dt) override;
    void Animated(const float& dt);
};