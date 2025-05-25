#include "Interactable.h"

Interactable::Interactable(float x, float y, float width, float height, SDL_Color color,
                           float wInteract, float hInteract)
    : Square(x, y, width, height, color), wInteract(wInteract), hInteract(hInteract) {}