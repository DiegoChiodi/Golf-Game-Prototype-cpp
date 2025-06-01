#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, 
           float wInteract, float hInteract, vector speed)
    : Interactable(x, y, width, height, color, wInteract, hInteract), speed(speed)
    {}

void Ball::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    Square::Run(dt, stat, renderer, camera);

    SetBallPPosition();

    switch (estage) {
        case Estage::PREVIEW:
            if (ballPreview != nullptr) {
                ballPreview->Run(dt, stat, renderer, camera);
            }
            break;
        case Estage::MOVING:
                if (ballPreview != nullptr) {
                    delete ballPreview;
                    ballPreview = nullptr;
                    InitialImpulse();
                } else {
                    this->BallMovement(dt);
                }
            break;
        default:
            break;
    }
}

void Ball::SetPreview() 
{
    ballPreview = new BallPreview(position.x, position.y, width, height, {70, 0, 70 , 255}, {80, 80});
    estage = Estage::PREVIEW;
}

void Ball::Render(SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    //this->RenderCollisor(renderer, camera);

    // 1. Desenhar sombra (mesma posição x,y da bola, no chão)
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 100); // sombra preta semi-transparente

    // Calcula posição da sombra relativa à câmera
    SDL_Rect sombraRect;
    sombraRect.w = this->width;
    sombraRect.h = this->height;
    sombraRect.x = static_cast<int>(this->position.x) - camera.x;
    sombraRect.y = static_cast<int>(this->position.y) - camera.y;

    // Desenha a sombra como um quadrado (ou retângulo)
    SDL_RenderFillRect(renderer, &sombraRect);

    SDL_Rect ballRect;
    ballRect.w = this->width;
    ballRect.h = this->height;
    ballRect.x = static_cast<int>(this->position.x) - camera.x;
    ballRect.y = static_cast<int>(this->position.y - camera.y - this->z); // Desloca a bola para cima pela altura Z
    // 2. Desenhar a bola com cor normal, mas deslocada para cima pela altura Z (height)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    
    SDL_RenderFillRect(renderer, &ballRect);
}


void Ball::Boost(point distance) 
{
    ballPreview->SetPosition(
        {
            distance.x / 2, 
            distance.y / 2
        }
    );
}

void Ball::BallMovement(const float& dt) {
    // Aplica atrito horizontal corretamente: v = v0 * exp(-k * dt)
    float frictionFactor = std::exp(-this->friction * dt);
    this->speed.x *= frictionFactor;
    this->speed.y *= frictionFactor;

    // Atualiza posição horizontal
    this->position.x += this->speed.x * dt;
    this->position.y += this->speed.y * dt;

    /*if (this->position.x < this->checkZ.x )
    {
        this->z += this->speedZ * dt; // Aumenta a altura Z
        std::cout << "Aumentando Z: " << this->z << std::endl;
    } else {
        this->z -= this->speedZ * dt; // Diminui a altura Z
        std::cout << "Diminuindo Z: " << this->z << std::endl;
    }*/

    // Aplica gravidade
    this->speedZ -= this->gravity * 15 * dt; // A velocidade Z diminui com a gravidade
    this->z += this->speedZ * dt; // Atualiza a altura Z

    // Verifica se a bola toca o chão
    if (this->z < 0.0f) {
        this->speedZ *= -0.6f; // Z não pode ser negativo    
        this->z = 0.0f; // Reseta Z para 0 quando toca o 
        this->speed.x *= groundFriction; // Aplica atrito horizontal
        this->speed.y *= groundFriction;
    }

    if (this->speed.x < 8.0f && this->speed.x > -8.0f && this->speed.y < 8.0f && this->speed.y > -8.0f) {
        this->speedZ *= 0.98f; // Reduz a velocidade Z quando a bola está quase parada
    }

    if (this->z == 0.0f)
    {
        this->speed.x *= this->groundFriction; // Aplica atrito no chão
        this->speed.y *= this->groundFriction; // Aplica atrito no chão
    }
    std::cout << "Z: " << this->z << std::endl;

}


void Ball::InitialImpulse() {
    // Vetor da mira até a bola
    distanceVector.x = ballPPosition.x - this->position.x;
    distanceVector.y = ballPPosition.y - this->position.y;

    // Distância entre bola e preview
    distance = std::sqrt(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);
    
    this->checkZ.x =  distance / 3.0f + distance; // Limite Z proporcional à distância
    this->checkZ.y = (distance / 3.0f) + distance; // Limite Z proporcional à distância

    // Evitar divisão por zero
    if (distance == 0.0f) return;
    
    // Limitar a distância máxima (força máxima)
    float distanciaMax = 220.0f;
    if (distance > distanciaMax) distance = distanciaMax;
    // Normalizar direção usando vector
    vector dir = { distanceVector.x / distance,
         distanceVector.y / distance };

    // Cálculo da força proporcional
    float forcaFinal = (distance / distanciaMax) * 300.0f;

    // Aplicar vetor força
    this->forca.x = dir.x * forcaFinal;
    this->forca.y = dir.y * forcaFinal;

    // Velocidade inicial
    this->speed.x = this->forca.x;
    this->speed.y = this->forca.y;

    // ---- Velocidade vertical (Z) proporcional à força total
    this->speedZ = forcaFinal * 0.625f;
}

bool Ball::Stop() const
{
    const float deadZone = 1.0f;
    return (std::abs(this->speed.x) < deadZone && std::abs(this->speed.y) < deadZone);
}

void Ball::InteractAction() {
}