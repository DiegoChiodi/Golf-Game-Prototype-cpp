#pragma once

#include "Interactable.h"
#include "BallPreview.h" 
#include "iostream"

class Ball : public Interactable {
protected:
    BallPreview* ballPreview = nullptr;
    vector speed; // Velocidade da bola
    enum class Estage { 
        IDLE, 
        PREVIEW,
        MOVING,
    };
    Estage estage = Estage::IDLE;
public:
    Ball(float x, float y, float width, float height, SDL_Color color,
         float wInteract, float hInteract, vector speed);
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void InteractAction() override;
    Estage GetEstage() const { return estage; }
    void SetEstage(Estage estageClaim) { this->estage = estageClaim; }
};