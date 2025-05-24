#include "GameWorld.h"

const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer, SDL_Texture* playerTexture, SDL_Texture* playerTextureSprinting)
    : renderer(renderer)
{
    // Crie o player e mantenha um ponteiro separado para fácil acesso
    auto p = std::make_unique<Player>(200, 100, 10, 20, SDL_Color{50, 50, 255, 255}, vector{35, 35}, playerTexture, playerTextureSprinting);
    player = p.get(); // Armazena o ponteiro do player

    objects.push_back(std::move(p)); // Adiciona o player à lista de objetos

    // Crie a bola e o hold, armazene-os diretamente em objects
    objects.push_back(std::make_unique<Ball>(
        100, 100, 5, 5, SDL_Color{255, 255, 255, 255}, vector{0, 0}, 20, 20
    ));
}

GameWorld::~GameWorld()
{

}

void GameWorld::Run(const float& dt ,const Uint8* stat)
{

    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer);

    // Atualiza o temporizador de interação
    if (this->interactTimer <= this->interactDelay) {
        this->interactTimer += dt;
    }

    // Atualiza todos os objetos do jogo
    for (auto& object : objects) {

        object->Run(dt, stat, renderer);
        // Verifica colisões entre objetos
        for (auto& other : objects) {
            if (object != other) { // Não verificar colisão consigo mesmo
                Square* square = dynamic_cast<Square*>(object.get());
                Square* square2 = dynamic_cast<Square*>(other.get());
                                
                if (square && square2) {
                    if (square->CheckCollision(square2->GetPosition(), square2->GetWidth(), square2->GetHeight())) {

                    }
                }

                if (player == square && square2 && this->interactDelay < this->interactTimer) {
                    Interactable* interactable = dynamic_cast<Interactable*>(square2);
                    if (interactable) {
                        // Verifica se o objeto é interativo
                        if (player->CheckCollision(interactable->GetPositionColliser(),
                            interactable->GetInteractW(), interactable->GetInteractH())) 
                        {
                            if (GameWorld::InteractAction(stat)) {
                                // Chama a ação de interação do objeto
                                interactable->InteractAction();
                                this->interactTimer = 0.0f; // Reinicia o temporizador de interação
                            }
                        }
                    }
                }
            }
        }
    }

    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(16); // Aproximadamente 60 FPS
}

bool GameWorld::InteractAction(const Uint8* stat)
{
    return stat[SDL_SCANCODE_SPACE];
}