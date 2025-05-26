#include "Ball.h"

Ball::Ball(float x, float y, float width, float height, SDL_Color color, 
           float wInteract, float hInteract, vector speed)
    : Interactable(x, y, width, height, color, wInteract, hInteract), speed(speed)
    {}

void Ball::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    Square::Run(dt, stat, renderer, camera);

    if (estage == Estage::PREVIEW) {
        ballPreview->Run(dt, stat, renderer, camera);
        if (stat[SDL_SCANCODE_SPACE]) {
            
            // Inicia o movimento da bola 
        }
    }
    
    if (ballPreview != nullptr) {
        ballPreview->Run(dt, stat, renderer, camera);
    }
}

void Ball::InteractAction() 
{
    ballPreview = new BallPreview(position.x, position.y, width, height, {70, 0, 70 , 255}, {125, 125});
    estage = Estage::PREVIEW;
}

void Ball::Render(SDL_Renderer* renderer, const SDL_Rect& camera) 
{
    RenderCollisor(renderer, camera);
    Square::Render(renderer, camera);
}