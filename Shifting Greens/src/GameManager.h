#pragma once
 
#include <algorithm>
#include <stdexcept>

#include "GameWorld.h" // importar

class GameManager {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Music* musicTable;
    Mix_Chunk* strokeSound;
    Mix_Chunk* holeSound;
    SDL_Texture* playerTexture;
    bool running;
    SDL_Event event;
    float dt;
    Uint32 previousTime;
    std::unique_ptr<GameWorld> gameWorld;
public:
    GameManager();
    ~GameManager();
    void Run();
    void Initialize();
};  