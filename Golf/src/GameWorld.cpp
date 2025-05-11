#include "GameWorld.h"
#include "circle.h"

#include <SDL2/SDL.h>

GameWorld::GameWorld() {
    // Usando std::unique_ptr para garantir gerenciamento de memória
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(100, 100, 50);
    objects.push_back(std::move(circle)); // Move o ponteiro para a lista
}

GameWorld::~GameWorld();
void GameWorld::Initialize();
void GameWorld::Update();

void GameWorld::Render()
{
    // Render game objects
    SDL_SetRenderDrawColor(renderer, 77, 255, 77, 255);
    SDL_RenderClear(renderer);
    for (auto& object : gameObjects) {
        object->Render(renderer);
    }
    SDL_RenderPresent(renderer);
}
void GameWorld::HandleInput(SDL_Event& event);
void GameWorld::Cleanup();
