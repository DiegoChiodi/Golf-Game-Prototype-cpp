#include "GameWorld.h"

const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer)
    : renderer(renderer)
{
    std::unique_ptr<GameObject> ball = std::make_unique<Ball>
    (100, 100, 100, 100, SDL_Color{255, 0, 0, 255}, vector{30, 0});

    std::unique_ptr<GameObject> hold = std::make_unique<Square>
    (100, 100, 50, 50, SDL_Color{0, 0, 255, 255});

    objects.push_back(std::move(ball)); // Move o ponteiro para a lista
    objects.push_back(std::move(hold)); // Move o ponteiro para a lista

}

GameWorld::~GameWorld()
{

}

void GameWorld::Run(float dt)
{

    // Atualiza todos os objetos do jogo
    for (auto& object : objects) {

        object->Run(dt);

        // Verifica colisões entre objetos
        for (auto& other : objects) {
            if (object != other) { // Não verificar colisão consigo mesmo
                Square* square = dynamic_cast<Square*>(object.get());
                Square* square2 = dynamic_cast<Square*>(other.get());
                                
                if (square && square2) {
                    if (square->CheckCollision(square2->GetPosition(), square2->GetWidth(), square2->GetHeight())) {

                    }
                }            
            }
        }
    }

    GameWorld::Render();
}

void GameWorld::Render()
{
    // Render game objects
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer);
    
    
    for (auto& object : objects) {
        object->Render(this->renderer);
    }

    SDL_RenderPresent(renderer);
    
    SDL_Delay(16); // Aproximadamente 60 FPS
    
}
void GameWorld::HandleEvents(SDL_Event& event)
{

}