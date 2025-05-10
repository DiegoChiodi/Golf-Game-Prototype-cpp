#include "GameManager.h" 
#include <iostream> 
#include <algorithm>
#include <stdexcept>

// Defina a resolução da janela
const int widthJan = 800;
const int heightJan = 600;

GameManager::GameManager()
    : window(nullptr), renderer(nullptr), musicTable(nullptr), stroke(nullptr), hole(nullptr), running(true)
{
    std::cout << "Inicializando o GameManager...\n";

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        throw std::runtime_error("Erro ao inicializar SDL: " + std::string(SDL_GetError()));
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        throw std::runtime_error("Erro ao inicializar SDL_mixer: " + std::string(Mix_GetError()));
    }

    window = SDL_CreateWindow("Golf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widthJan, heightJan, SDL_WINDOW_SHOWN);
    if (!window) {
        throw std::runtime_error("Erro ao criar janela: " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        throw std::runtime_error("Erro ao criar renderizador: " + std::string(SDL_GetError()));
    }

    musicTable = Mix_LoadMUS("assets/music/musicTable.mp3");
    if (!musicTable) {
        std::cerr << "Erro ao carregar música: " << Mix_GetError() << std::endl;
    }

    stroke = Mix_LoadWAV("assets/effect/stroke.mp3");
    if (!stroke) {
        std::cerr << "Erro ao carregar efeito sonoro 'stroke': " << Mix_GetError() << std::endl;
    }

    hole = Mix_LoadWAV("assets/effect/hole.mp3");
    if (!hole) {
        std::cerr << "Erro ao carregar efeito sonoro 'hole': " << Mix_GetError() << std::endl;
    }

    if (musicTable) {
        Mix_PlayMusic(musicTable, -1);
        std::cout << "Música carregada e tocando...\n";
    }
}

void GameManager::Run() {
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

GameManager::~GameManager()
{
    std::cout << "Finalizando o GameManager...\n";

    if (stroke) Mix_FreeChunk(stroke);
    if (hole) Mix_FreeChunk(hole);
    if (musicTable) Mix_FreeMusic(musicTable);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}