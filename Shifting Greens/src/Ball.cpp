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
                }
                this->BallMovement(dt);
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
    this->RenderCollisor(renderer, camera);
    Square::Render(renderer, camera);
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

    // Aplica atrito corretamente: v = v0 * exp(-k * dt)
    float frictionFactor = std::exp(-this->friction * dt);
    this->speed.x *= frictionFactor;
    this->speed.y *= frictionFactor;
    
    this->position.x += this->speed.x * dt;
    this->position.y += this->speed.y * dt;
}

void Ball::InitialImpulse() {
    // Vetor da mira até a bola
    float dx = ballPPosition.x - this->position.x;
    float dy = ballPPosition.y - this->position.y;

    // Distância entre bola e preview
    float distancia = std::sqrt(dx * dx + dy * dy);

    // Evitar divisão por zero
    if (distancia == 0.0f) return;

    // Limitar a distância máxima (força máxima)
    float distanciaMax = 120.0f;
    if (distancia > distanciaMax) distancia = distanciaMax;
    // Normalizar direção usando vector
    vector dir = { dx / distancia,
         dy / distancia };

    // Cálculo da força proporcional
    float forcaFinal = (distancia / distanciaMax) * 100.0f;

    // Aplicar vetor força
    this->forca.x = dir.x * forcaFinal;
    this->forca.y = dir.y * forcaFinal;

    // Velocidade inicial
    this->speed.x = this->forca.x;
    this->speed.y = this->forca.y;
}

bool Ball::Stop() const
{
    const float deadZone = 0.15f;
    return (std::abs(this->speed.x) < deadZone && std::abs(this->speed.y) < deadZone);
}


void Ball::InteractAction() {
}