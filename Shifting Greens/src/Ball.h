#pragma once

#include "Interactable.h"
#include "BallPreview.h" 
#include <iostream>

class Ball : public Interactable {
public:
    
    //Normal functions --------------------------------
    Ball(float x, float y, float width, float height, SDL_Color color,
         float wInteract, float hInteract, vector speed);
    void Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void Render(SDL_Renderer* renderer, const SDL_Rect& camera) override;
    //Herder functions --------------------------------
    void InteractAction() override;
    //BallPreview functions ------------------------
    void Boost(point distance);
    BallPreview* GetBallPreview() const { return ballPreview; }
    //Estage functions and variables ------------------------
    enum class Estage {
        IDLE,
        PREVIEW,
        MOVING
    };
    Estage GetEstage() const { return this->estage; }
    void SetEstage(Estage estageClaim) { this->estage = estageClaim; }
    void SetPreview ();
    //Fisic functions --------------------------------
    vector calculateForce();
    void InitialImpulse();
    void BallMovement(const float& dt);
protected:
    BallPreview* ballPreview = nullptr;
    vector speed; // Velocidade da bola
    Estage estage = Estage::IDLE;
    float atrito = 0.98f; // Fator de atrito para desacelerar a bola
    float zDimension = 0.0f; // Dimensão Z para simular profundidade
};