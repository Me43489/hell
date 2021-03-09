#include <string>
#include <iostream> 
#include "texturemanager.hpp"
#include "game.hpp"


void TextureManager::Destroy()
{
    for (auto i : TextureManager::Images) SDL_DestroyTexture(i.second);
}

bool TextureManager::Load(std::string filename, std::string name)
{
    SDL_Texture* texture = IMG_LoadTexture(Display::GetRenderer(), filename.c_str());
    if (texture == nullptr) {
        std::cout << "Failed to load:" << filename << "\n";
    }
    Images[name] = texture;
    return false;
}

SDL_Texture* TextureManager::Get(std::string name, int gridSizeX, int gridSizeY, int x, int y, SDL_Rect& dest) {
    SDL_Texture* tex = Images[name];
    if (tex == nullptr) return tex;
    dest.x = gridSizeX * x;
    dest.y = gridSizeY * y;
    dest.w = gridSizeX;
    dest.h = gridSizeY;
    return tex;
}

SDL_Texture* TextureManager::Get(std::string name, SDL_Rect& dest)
{
    SDL_Texture* tex = Images[name];
    Uint32 fmt;
    int acs;
    dest.x = 0;
    dest.y = 0;
    SDL_QueryTexture(tex, &fmt, &acs, &dest.w, &dest.h);

    return tex;
}

SDL_Texture* TextureManager::Get(std::string name)
{
    SDL_Texture* tex = Images[name];
    /*Uint32 fmt;
    int acs;
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    SDL_QueryTexture(tex, &fmt, &acs, &dest.w, &dest.h);*/
    return tex;
}

//Statics
std::map<std::string, SDL_Texture*> TextureManager::Images;



