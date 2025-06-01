#pragma once

#include "Movel.h"
#include <SDL2/SDL2_gfxPrimitives.h>

class BallPreview : public Movel {
public:
    BallPreview(float x, float y, float width, float height, SDL_Color color, vector speed);
    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void SetWidthCircle(int width) { widthCircle = width; }
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) override;
protected:
    int widthCircle = 0;
};