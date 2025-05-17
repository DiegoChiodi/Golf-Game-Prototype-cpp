#include "GameWorld.h"

const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer)
    : renderer(renderer)
{
    std::unique_ptr<GameObject> hold = std::make_unique<Circle>
    (500, 100, CollisionType::CIRCLE, SDL_Color{0, 0, 0, 255}, 50);

    std::unique_ptr<GameObject> player = std::make_unique<Ball>
    (100, 100, CollisionType::CIRCLE, SDL_Color{255, 255, 255, 255}, 50);

    objects.push_back(std::move(hold)); // Move o ponteiro para a lista
    objects.push_back(std::move(player)); // Move o ponteiro para a lista
}

GameWorld::~GameWorld()
{

}

void GameWorld::Run()
{
    // Atualiza todos os objetos do jogo
    for (auto& object : objects) {
        object->Run();


        // Verifica colisões entre objetos
        for (auto& other : objects) {
            if (object != other) { // Não verificar colisão consigo mesmo
                if (object->GetCollisionType() == CollisionType::CIRCLE && other->GetCollisionType() == CollisionType::CIRCLE) {
                    Circle* circle1 = dynamic_cast<Circle*>(object.get());
                    Circle* circle2 = dynamic_cast<Circle*>(other.get());
                    if (circle1 && circle2) {
                        if (circle1->CheckCollisionCircle(circle2->GetFormat())) {
                            std::cout << "Colisão detectada entre objetos!" << std::endl;
                        }
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
