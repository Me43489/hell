#pragma once

/*****************************
			Instance of Game Class
******************************/

#include <string>
#include <stack>
#include "texturemanager.hpp"
#include <functional>
#include "display.hpp"
#include "audiomanager.hpp"

class  Game {
private:

	bool running;
	SDL_Event event;
	SDL_Texture* backround;
	bool paused;

	float angle = 0.0;
	int  PreviousWheelPos = 0;
	void update();
	void render();
	void WheelStopped();
	std::function<void(void)>onStop;
public:
	Game(std::string title, int w, int h);
	void run();
	void quit();
};
