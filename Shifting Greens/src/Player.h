#pragma once

#include "Movel.h"

class Player : public Movel {
    public:
    Player(float x, float y, float width, float height, SDL_Color color, vector speed);
<<<<<<< HEAD
    void HandleEvents(SDL_Event& event, const Uint8* stat, const float &dt) override;
=======
    void HandleEvents(SDL_Event& event) override;
>>>>>>> 4dfb594f4ef983018865a22bf328aee07b31894c
};