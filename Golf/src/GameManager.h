#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class GameManager {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Music* musicTable;
    Mix_Chunk* stroke;
    Mix_Chunk* hole;
    bool running;
    SDL_Event event;

public:
    GameManager();
    ~GameManager();
    void Run();
};  