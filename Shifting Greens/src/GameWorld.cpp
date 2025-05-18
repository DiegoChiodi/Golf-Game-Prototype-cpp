#include "GameWorld.h"

const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer)
    : renderer(renderer)
{
    std::unique_ptr<GameObject> player = std::make_unique<Ball>
    (100, 100, 100, 100, SDL_Color{255, 0, 0, 255});

    std::unique_ptr<GameObject> hold = std::make_unique<Square>
    (100, 100, 50, 50, SDL_Color{0, 0, 255, 255});


    objects.push_back(std::move(player)); // Move o ponteiro para a lista
    objects.push_back(std::move(hold)); // Move o ponteiro para a lista

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
                Square* square = dynamic_cast<Square*>(object.get());
                Square* square2 = dynamic_cast<Square*>(other.get());
                
                if (square && square2) {
                    if (square->CheckCollision(square2->GetPosition(), square2->GetWidth(), square2->GetHeight())) {
                        std::cout << "Colisão detectada entre quadrados!" << std::endl;
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
    float dt = (currentTime - previousTime) / 1000.0f; // dt em segundos
    previousTime = currentTime;

    const Uint32 targetTime = 1000 / 60; // Target 60 FPS

    if ((currentTime - previousTime) < targetTime) {
        SDL_Delay(targetTime - (currentTime - previousTime));
    }
    std::cout << "dt: " << dt << std::endl;
}
void GameWorld::HandleEvents(SDL_Event& event)
{

}