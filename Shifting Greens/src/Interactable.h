#pragma once 

#include "Movel.h"

class Interactable : public Movel {
protected:
    float wInteract, hInteract; // Position of the interaction
public:
    Interactable(float x, float y, float width, float height, SDL_Color color, vector speed,
         float wInteract, float hInteract);

    virtual void InteractAction() = 0; // Pure virtual function for interaction
    virtual GetInteractW() const { return wInteract; }
    virtual GetInteractH() const { return hInteract; }
};