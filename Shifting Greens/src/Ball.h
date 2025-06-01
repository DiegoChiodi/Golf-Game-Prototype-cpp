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
    void InitialImpulse();
    void BallMovement(const float& dt);
    void SetBallPPosition() {  
        if (ballPreview) {
            ballPPosition = ballPreview->GetPosition();
        }
    }
    bool Stop () const;
protected:
    BallPreview* ballPreview = nullptr;
    vector speed; // Velocidade da bola
    Estage estage = Estage::IDLE;
    float zDimension = 0.0f; // Dimensão Z para simular profundidade
    vector forca = {0.0f, 0.0f}; // Força aplicada na bola
    float friction = 0.98f; // Fator de atrito para desacelerar a bola
    vector ballPPosition; // Posição da bola para o preview
    //Váriaveis do z ---------------
    float z = 0.0f;
    float speedZ = 0.0f;
    vector checkZ = {0.0f, 0.0f};
    float dx = ballPPosition.x - this->position.x / 2;
    float dy = ballPPosition.y - this->position.y / 2;
    vector distanceVector = {0.0f, 0.0f};
    float distance = 0.0f; // Distância entre a bola e o preview
    const float gravity = 10.0f;
    const float groundFriction = 0.95; // Fator de atrito do chão
};
