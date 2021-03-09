#pragma once
#include <string>
#include <map>
#include "SDL_image.h"


class TextureManager {
private:

public:
	static void Destroy();
	static std::map<std::string, SDL_Texture*> Images;


	static bool Load(std::string filename, std::string name);
	static SDL_Texture* Get(std::string name, int GridSizeX, int GridSizeY, int x, int y, SDL_Rect& dest);
	static SDL_Texture* Get(std::string name, SDL_Rect& dest);
	static SDL_Texture* Get(std::string name);
};

