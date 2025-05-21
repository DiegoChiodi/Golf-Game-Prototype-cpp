#include "Interactable.h"

Interactable::Interactable(float x, float y, float width, float height, SDL_Color color, vector speed,
                           float wInteract, float hInteract)
    : Movel(x, y, width, height, color, speed), wInteract(wInteract), hInteract(hInteract) {}