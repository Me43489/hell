#pragma once
/*****************************
			Instance of Space Class
******************************/
#include <SDL.h>
#include <SDL_image.h>
#include "chip.hpp"

class Space {
private:
	bool available;
	SDL_Point cords;
	Chip chip;
public:
	bool isAvailable();
	SDL_Point getCords();
};