#pragma once

/*****************************
			Instance of Chip Class
******************************/
#include <SDL.h>

class Chip {
private:
	bool color;
	static SDL_Point pos;
public:
	void Place(int x, int y);
	void die();
	void capture();
};
