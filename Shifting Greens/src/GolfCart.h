#pragma once

#include "Interactable.h"

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
}