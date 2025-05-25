#pragma once

#include "Movel.h"
#include <SDL2/SDL_image.h>


class Player : public Movel {
private:
    SDL_Texture* actualTexture;
    SDL_Texture* textureUpright;
    SDL_Texture* textureSprinting;

    bool animate = false;
    float delayAnimate = 0.1f;
public:
    Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright, SDL_Texture* textureSprinting);
    void Render(SDL_Renderer* renderer) override;
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) override;
    void Animated(const float& dt);
};