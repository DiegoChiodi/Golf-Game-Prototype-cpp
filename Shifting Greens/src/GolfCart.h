#pragma once

#include "Interactable.h"
#include <iostream>

class GolfCart : public Interactable {
private:
    vector speed;
public:
    GolfCart(float x, float y, float width, float height, SDL_Color color,
             float wInteract, float hInteract, vector speed);
    void InteractAction() override {
        // Implementar ação de interação
        std::cout << "Interagindo com o carrinho de golfe!" << std::endl;
    }

    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;

    void HandleEvents(const Uint8* stat, const float& dt);
};