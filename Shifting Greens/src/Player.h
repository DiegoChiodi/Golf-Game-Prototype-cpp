#pragma once

#include "Movel.h"
#include <SDL2/SDL_image.h>


class Player : public Movel {
private:
    SDL_Texture* textureUpright;
public:
    Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright);
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float &dt) override;
    void Render(SDL_Renderer* renderer) override;
    void Run(const float& dt) override;
};