#pragma once

#include "Movel.h"

class Player : public Movel {
public:
    Player(float x, float y, float width, float height, SDL_Color color, vector speed);
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float &dt) override;
};