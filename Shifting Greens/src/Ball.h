#pragma once

#include "Interactable.h"
#include "BallDisplacement.h" 
#include "iostream"

class Ball : public Interactable {
protected:
    BallDisplacement* ballDisplacement = nullptr;
public:
    Ball(float x, float y, float width, float height, SDL_Color color, vector speed,
         float wInteract, float hInteract);
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer) override;
    void Render(SDL_Renderer* renderer) override;
    void InteractAction() override {
        // Implementar ação de interação
        std::cout << "Interagindo com a bola!" << std::endl;
    }
};