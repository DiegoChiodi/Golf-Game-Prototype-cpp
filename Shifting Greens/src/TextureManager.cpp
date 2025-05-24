#include "TextureManager.h"
#include <SDL2/SDL_image.h>

bool TextureManager::LoadTexture(const std::string& id, const std::string& filepath, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(filepath.c_str());
    if (!tempSurface) return false;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (!texture) return false;

    textures[id] = texture;
    return true;
}

SDL_Texture* TextureManager::GetTexture(const std::string& id) const {
    auto it = textures.find(id);
    return (it != textures.end()) ? it->second : nullptr;
}

void TextureManager::Clear() {
    for (auto& pair : textures)
        SDL_DestroyTexture(pair.second);

    textures.clear();
}