#include "display.hpp"
#include<iostream>

Display::Display(int width, int height) {

	Display::Width = width;
	Display::Height = height;

	if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) < 0)
	{	
		std::cerr << "Failed to create display: " << SDL_GetError() << "\n";
	}
}

Display::~Display() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	delete displayInstance;
}

void Display::Create(int width, int height) {
	displayInstance = new Display(width, height);
}

void Display::Clear(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(GetRenderer(), r, g, b, 255);
	SDL_RenderClear(GetRenderer());
}

void Display::Present()
{
	SDL_RenderPresent(GetRenderer());
}

void Display::DrawTexture(SDL_Texture* texture)
{
	SDL_RenderCopy(GetRenderer(), texture, NULL, NULL);
}

void Display::DrawTexture(SDL_Texture* texture, const SDL_Rect targetRect)
{
	SDL_RenderCopy(GetRenderer(), texture, NULL, &targetRect);
}

void Display::DrawTexture(SDL_Texture* texture, const SDL_Rect targetRect, const SDL_Rect subTexture)
{
	SDL_RenderCopy(GetRenderer(), texture, &targetRect, &subTexture);
}
/************************************
			statics
***********************************/

int Display::Width = 0;
int Display::Height = 0;
Display* Display::displayInstance = NULL;