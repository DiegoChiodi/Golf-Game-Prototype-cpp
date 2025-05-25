#pragma once

#include "Movel.h"

class GolfCartMoviment : public Movel {
public:
    GolfCartMoviment(float x, float y, float width, float height, SDL_Color color, vector speed);

    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;

    void HandleEvents(const Uint8* stat, const float& dt);
};