#include "GameManager.h"
#include <iostream> 
#include <algorithm>
#include <stdexcept>

// Defina a resolução da janela
const int widthJan = 800;
const int heightJan = 600;

GameManager::GameManager()
    : window(nullptr), renderer(nullptr), musicTable(nullptr), strokeSound(nullptr), holeSound(nullptr), running(true)
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

    strokeSound = Mix_LoadWAV("assets/effect/stroke.mp3");
    if (!strokeSound) {
        std::cerr << "Erro ao carregar efeito sonoro 'stroke': " << Mix_GetError() << std::endl;
    }

    holeSound = Mix_LoadWAV("assets/effect/hole.mp3");
    if (!holeSound) {
        std::cerr << "Erro ao carregar efeito sonoro 'hole': " << Mix_GetError() << std::endl;
    }

    if (musicTable) {
        Mix_PlayMusic(musicTable, -1);
        std::cout << "Música carregada e tocando...\n";
    }

    GameManager::Initialize();
}

void GameManager::Run() {
    SDL_Event event;
    while (running) {
        gameWorld->Run();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_SPACE:
                    Mix_PlayChannel(-1, strokeSound, 0);
                    break;
                case SDLK_RETURN:
                    Mix_PlayChannel(-1, holeSound, 0);
                    break;
                default:
                    break;
            }
            }
        }
        
    }
}

void GameManager::Initialize() {
    std::cout << "Inicializando o GameWorld...\n";
    gameWorld = std::make_unique<GameWorld>(renderer);
}

GameManager::~GameManager()
{
    std::cout << "Finalizando o GameManager...\n";

    if (strokeSound) Mix_FreeChunk(strokeSound);
    if (holeSound) Mix_FreeChunk(holeSound);
    if (musicTable) Mix_FreeMusic(musicTable);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}