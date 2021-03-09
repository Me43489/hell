/**********************************
       Implementation of Class game
**********************************/
#include "texturemanager.hpp"
#include "textureconst.hpp"
#include "game.hpp"
#include "board.hpp"
#include "display.hpp"
#include <iostream>
#include <iterator>
#include <SDL_mixer.h>


Game::Game(std::string title, int w, int h) :event() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
        std::cerr << "SDL was unable to be initalized" << SDL_GetError() << std::endl;
        running = false;
        Game::quit();
    }
    
    Display::Create(w, h);
    // Loads the Textures
    TextureManager::Load(".\\assets\\fire-backround.jpg",BACKROUND);
    backround = TextureManager::Images[BACKROUND];
    
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) < 0){
        SDL_ShowSimpleMessageBox(0, "Error", "SDL_MIXER couldnt initalize", Display::GetWindow());
        exit(1);
    }
    AudioManager::LoadEffect(".\\assets\\shot.wav", "shot");
    AudioManager::LoadMusic(".\\assets\\Fire-burning.wav","fire");
    running = true;
    

}

void Game::render() {

   //' SDL_Rect chip = { BOARD_BOARD_OFFSET + 16,32,64,64 };

    SDL_RenderClear(Display::GetRenderer());
    SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Display::GetRenderer());
    SDL_SetRenderDrawColor(Display::GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
    
    Display::DrawTexture(backround);
    //TextureManager::draw(BOARD, board_dest::h,board_dest::w, board_dest::x, board_dest::y);
    //TextureManager::draw(RED_CHIP, 100, 100, 100, 100);
    //SDL_RenderCopy(renderer,TextureManager::images["Board"].data, &texture->src, &texture->dest);
    //SDL_RenderCopy(renderer, texture->data, &texture->src, &texture->dest);
    Display::Present();
}

void Game::update() {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            Mix_PlayChannel(-1, AudioManager::Effects["shot"], 0);
        }
    }
}

void Game::run() {
    Mix_PlayMusic(AudioManager::SoundTracks["fire"], -1);

    while (running) {
        update();
        render();
    }
}


void Game::quit() {
    running = false;
}

/****************************
STATIC MEMBERS OF CLASS GAME:
*****************************/

