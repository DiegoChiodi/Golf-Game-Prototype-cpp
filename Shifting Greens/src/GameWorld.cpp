#include "GameWorld.h"

const SDL_Color BACKGROUND_COLOR = {77, 255, 77, 255};

GameWorld::GameWorld(SDL_Renderer* renderer, TextureManager* textureManager)
    : renderer(renderer), textureManager(textureManager), camera()
{
    // Crie o player e mantenha um ponteiro separado para fácil acesso
    auto p = std::make_unique<Player>(200, 100, 10, 20, SDL_Color{50, 50, 255, 255}, vector{60, 60},
    this->textureManager->GetTexture("GolferUpright"), 
    this->textureManager->GetTexture("GolferSprinting"));

    player = p.get(); // Armazena o ponteiro do player
    viewTarget = player;    // Define o ponto de destino da câmera como o player

    objects.push_back(std::move(p)); // Adiciona o player à lista de objetos

    // Crie a bola e o hold, armazene-os diretamente em objects

    auto b = std::make_unique<Ball>(
        100, 100, 5, 5, SDL_Color{255, 255, 255, 255}, 20, 20, vector{0, 0}
    );

    ball = b.get(); // Armazena o ponteiro da bola

    objects.push_back(std::make_unique<Hole>(
        300, 300, 10, 10, SDL_Color{255, 0, 0, 255}, b.get()
    ));

    objects.push_back(std::move(b));

    
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

    this->camera.update(
        this->viewTarget->GetPosition().x, 
        this->viewTarget->GetPosition().y, 
        Global::MAP_WIDTH,
        Global::MAP_HEIGHT
        );

    // Atualiza todos os objetos do jogo
    for (auto& object : objects) {

        object->Run(dt, stat, renderer, this->camera.getView());
        // Verifica colisões entre objetos
        for (auto& other : objects) {
            if (object != other) 
            { // Não verificar colisão consigo mesmo
                Colliders(dt, stat, object.get(), other.get());
            }
        }
    }

    //BallPreview* ballPreview = dynamic_cast<BallPreview*>(viewTarget);

    if (this->ball->GetEstage() == Ball::Estage::PREVIEW) {
        if (InteractAction(stat) && this->interactTimer >= this->interactDelay) {
            this->player->SetState(MovingState::IDLE_CENTRAL);
            this->ball->SetEstage(Ball::Estage::MOVING);
            this->viewTarget = this->player;
            this->interactTimer = 0.0f; // Reinicia o temporizador de interação
        }
    }
    /*if (ballPreview) {

        if (InteractAction(stat) && this->interactTimer >= this->interactDelay) {
            player->SetState(MovingState::SPRINTING);
            viewTarget->GetOwner()->SetEstage(Ball::Estage::MOVING);
        }
    }*/
    
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(16); // Aproximadamente 60 FPS
}

bool GameWorld::InteractAction(const Uint8* stat)
{
    return stat[SDL_SCANCODE_SPACE];
}

void GameWorld::Colliders(const float& dt, const Uint8* stat, GameObject* object, GameObject* other)
{
    Square* square = dynamic_cast<Square*>(object);
    Square* square2 = dynamic_cast<Square*>(other);
                    
    if (square && square2) {
        Ball* ball = dynamic_cast<Ball*>(square);

        if (square->CheckCollision(square2->GetPosition(), square2->GetWidth(), square2->GetHeight())) {

        }
    }
    if (player == square && square2 && this->interactDelay < this->interactTimer) 
    {
        Interactable* interactable = dynamic_cast<Interactable*>(square2);
        if (interactable) {
            // Verifica se o objeto é interativo
            if (player->CheckCollision(interactable->GetPositionColliser(),
                interactable->GetInteractW(), interactable->GetInteractH())) 
            {
                if (GameWorld::InteractAction(stat) && this->interactTimer >= this->interactDelay) {
                    // Chama a ação de interação do objeto
                    interactable->InteractAction();
                    this->interactTimer = 0.0f; // Reinicia o temporizador de interação
                    if (this->ball && this->ball->GetEstage() == Ball::Estage::IDLE)
                    {
                        this->ball->SetPreview();
                        this->player->SetState(MovingState::IDLE);
                        viewTarget = this->ball->GetBallPreview();
                        Hole* hole = nullptr;

                        for (auto& hole : objects) {
                            Hole* h = dynamic_cast<Hole*>(hole.get());
                            if (h && h->GetBall() == ball) {
                                point distance = {
                                    h->GetPosition().x + ball->GetPosition().x,
                                    h->GetPosition().y + ball->GetPosition().y
                                }; 
                                ball->Boost(distance);
                            }
                        }
                    }
                }
            }
        }
    }
}