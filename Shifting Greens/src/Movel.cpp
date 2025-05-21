#include "Movel.h"

Movel::Movel(float x, float y, float width, float height, SDL_Color color, vector speed)
    : Square(x, y, width, height, color), speed(speed){}