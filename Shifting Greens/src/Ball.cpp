#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, 
           float wInteract, float hInteract, vector speed)
    : Interactable(x, y, width, height, color, wInteract, hInteract), speed(speed)
    {}

void Ball::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    Square::Run(dt, stat, renderer, camera);

    switch (estage) {
        case Estage::PREVIEW:
            if (ballPreview != nullptr) {
                ballPreview->Run(dt, stat, renderer, camera);
            }
            break;
        case Estage::MOVING:
                delete ballPreview;
                ballPreview = nullptr;
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
    RenderCollisor(renderer, camera);
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

vector Ball::calculateForce() {
    vector direcao;
    direcao.x = ballPreview->GetPosition().x - this->position.x;
    direcao.y = ballPreview->GetPosition().y - this->position.y;

    // Distância entre a bola e o ponto de mira
    float distancia = sqrt(direcao.x * direcao.x + direcao.y * direcao.y); //teorema de Pitágoras

    // Normalizar vetor
    if (distancia > 0) {
        direcao.x /= distancia;
        direcao.y /= distancia;
    }

    // Limitar distância para forcaMaxima
    float distanciaMax = 120.0f; // valor baseado no tamanho da tela (tune este valor)
    if (distancia > distanciaMax) distancia = distanciaMax;

    // Calcular força proporcional (escala de 0 até forcaMaxima)
    float forcaFinal = (distancia / distanciaMax) * 100.0f; // forcaMaxima é 100

    // Retornar vetor força
    return {
        direcao.x * forcaFinal,
        direcao.y * forcaFinal
    };
}

void Ball::InitialImpulse() {
}

void Ball::InteractAction() {
}

void Ball::BallMovement(const float& dt) {
}