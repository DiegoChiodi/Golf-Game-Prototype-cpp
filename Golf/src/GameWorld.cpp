#include "GameWorld.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer)
    : renderer(renderer)
{
    std::unique_ptr<GameObject> circle = std::make_unique<Circle>
    (100, 100, CollisionType::CIRCLE, SDL_Color{255, 0, 0, 255}, 50);

    objects.push_back(std::move(circle)); // Move o ponteiro para a lista
}

GameWorld::~GameWorld()
{

}
void GameWorld::Initialize()
{

}

void GameWorld::Run()
{
    // Atualiza todos os objetos do jogo
    for (auto& object : objects) {
        object->Run();
    }

    GameWorld::Render();
}

void GameWorld::Render()
{
    // Render game objects
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer);
    
    for (auto& object : objects) {
        object->Render(renderer);
    }

    filledCircleColor(renderer, 400, 400, 40, 0x0000FFFF); // Azul

    SDL_RenderPresent(renderer);
    static Uint32 previousTime = SDL_GetTicks();
    Uint32 currentTime = SDL_GetTicks();
    Uint32 dt = currentTime - previousTime;
    previousTime = currentTime;

    const Uint32 targetTime = 1000 / 60; // Target 60 FPS
    if (dt < targetTime) {
        SDL_Delay(targetTime - dt);
    }
}
void GameWorld::Cleanup()
{

}
