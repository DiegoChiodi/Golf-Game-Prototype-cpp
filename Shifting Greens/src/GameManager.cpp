#include "GameManager.h"

GameManager::GameManager()
    : window(nullptr), renderer(nullptr), musicTable(nullptr), strokeSound(nullptr), holeSound(nullptr), running(true)
{
    std::cout << "Inicializando o GameManager...\n";


    //Áudio e vídeo ------------------------------------------------------------------
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        throw std::runtime_error("Erro ao inicializar SDL: " + std::string(SDL_GetError()));
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        throw std::runtime_error("Erro ao inicializar SDL_mixer: " + std::string(Mix_GetError()));
    }

    //Janela e renderizador ---------------------------------------------------

    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
        throw std::runtime_error("Erro ao obter resolução da tela: " + std::string(SDL_GetError()));
    }

    window = SDL_CreateWindow("Shifting greens", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window) {
        throw std::runtime_error("Erro ao criar janela: " + std::string(SDL_GetError()));
    }
    
    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode(0, &dm);
    std::cout << "Resolução real do monitor: " << dm.w << "x" << dm.h << std::endl;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); // antes de criar o renderer

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        throw std::runtime_error("Erro ao criar renderizador: " + std::string(SDL_GetError()));
    }

    SDL_RenderSetLogicalSize(renderer, Global::LOGICAL_WIDTH, Global::LOGICAL_HEIGHT);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);    

    // Carregar Texturas ------------------------------------------------------------

    textureManager.LoadTexture("GolferUpright", "assets/sprites/Golfer/GolferUpright.png", renderer);
    textureManager.LoadTexture("GolferSprinting", "assets/sprites/Golfer/GolferSprinting.png", renderer);

    // Carregar música e efeitos sonoros ---------------------------------------------
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

    // Inicializar o GameWorld -------------------------------------------------------

    GameManager::Initialize();
}

void GameManager::Run() {

    SDL_Event event;
    const Uint8* stat = SDL_GetKeyboardState(nullptr);
    
    while (running) 
    {
        Uint32 currentTime = SDL_GetTicks();
        dt = (currentTime - previousTime) / 1000.0f; // dt em segundos
        previousTime = currentTime;
        
        gameWorld->Run(dt, stat);

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
                    case SDLK_r:
                        // Reinicializar o GameWorld
                        std::cout << "Reinicializando o GameWorld...\n";
                        gameWorld = std::make_unique<GameWorld>(renderer, &textureManager);
                        previousTime = SDL_GetTicks();
                        dt = 0.0f;
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
    gameWorld = std::make_unique<GameWorld>(renderer, &textureManager);
    previousTime = SDL_GetTicks();
    dt = 0.0f;
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