#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

class TextureManager {
private:
    std::unordered_map<std::string, SDL_Texture*> textures;
public:
    bool LoadTexture(const std::string& id, const std::string& filepath, SDL_Renderer* renderer);
    SDL_Texture* GetTexture(const std::string& id) const;
    void Clear(); // libera memória
};