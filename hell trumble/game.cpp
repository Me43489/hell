/**********************************
   Implementation of Class game
**********************************/

#include "texturemanager.hpp"
#include "textureconst.hpp"
#include "game.hpp"
#include "display.hpp"
#include "audioplayer.hpp"

#include <cmath>
#include <iostream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <SDL_mixer.h>


SDL_Point WheelCords[9];
int starttick = SDL_GetTicks();
int fps = 60;
int desiredDelta = 100 / fps;
int avgFPS;
int frame = 0;
int radius = 0;
float angleoffset = 0;


Game::Game(std::string title, int w, int h) :event() {
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
        std::cerr << "SDL was unable to be initalized" << SDL_GetError() << std::endl;
        running = false;
        Game::quit();
    }
    
    Display::Create(w, h);
    // Loads the Textures
    TextureManager::Load(".\\assets\\fire-backround.jpg",BACKROUND);
    TextureManager::Load(".\\assets\\circle2.png", "wheel");
    
    backround = TextureManager::Images[BACKROUND];
    
    AudioPlayer::Init();
    AudioManager::LoadMusic(".\\assets\\Fire-burning.wav","fire");
    AudioManager::LoadEffect(".\\assets\\single-bell.wav","bell");
    AudioManager::LoadEffect(".\\assets\\cool-sound.wav","cool");
    AudioManager::LoadEffect(".\\assets\\shot.wav", "shot"); 
    AudioManager::LoadEffect(".\\assets\\bang.wav", "pop");
    
    srand(time(NULL));
    onStop = std::bind(&Game::WheelStopped,this);
    running = true;
    paused = false;
    found = false;
}

void Game::render() {

   //' SDL_Rect chip = { BOARD_BOARD_OFFSET + 16,32,64,64 };
  
    //SDL_Rect test = { 10,10,414,242 };
    SDL_Rect test = {414,242,10,10};

    SDL_Rect srcwheel = { 0,0,352 * 2,352 * 2 };

    SDL_Rect wheel;
    wheel.h = 352*2;
    wheel.w = 352*2;
    wheel.x = 288;
    wheel.y = 160;
    
    int X = wheel.x - test.x;
    int Y = wheel.y - test.y;
    int distance = std::sqrt(std::pow((X),2)+std::pow((Y),2));
    int radius = 352;

  
    int cx = wheel.x + (wheel.w / 2);
    int cy = wheel.y + (wheel.h / 2);

    /*for (int i = 0; i < 9; i++) {
        int ANGLE = 40 * i;
        int px = cx + std::sin(ANGLE * M_PI / 180) * radius;
        int py = cy - std::sin(ANGLE * M_PI / 180) * radius;
        SDL_Rect test2 = { px,py,10,10 };
        SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(Display::GetRenderer(), &test2);
    }*/

    SDL_Rect BackRoundRect;
    BackRoundRect.h = Display::Height;
    BackRoundRect.w = Display::Width;
    BackRoundRect.x = 0;
    BackRoundRect.y = 0;
    
    //int x = 160 + (352 - (352 *(int)cos((2 / 9) * (M_PI))));
    
    SDL_RenderClear(Display::GetRenderer());
    SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Display::GetRenderer());
    

    Display::DrawTexture(backround,BackRoundRect);
    //Display::DrawTexture(TextureManager::Images["wheel"],wheel);
    angle += angleoffset + avgFPS;
    if (!found) {
        // angle += framerate;
        float radians = angle * M_PI / 180;
        Display::DrawTextureRot(TextureManager::Images["wheel"], srcwheel, wheel, angle);
        SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(Display::GetRenderer(), &test);

        int CurrentState = (int)(angle / 40);
        int i = 0;

        if (CurrentState != PreviousWheelPos) {
            Mix_PlayChannel(-1, AudioManager::Effects["pop"], 0);
            //std::cerr << "sound played\n";
            PreviousWheelPos = CurrentState;
        }
        //draws the dots on the circle
        for (int i = 0; i < 9; i++) {
            int ANGLE = 40 * i;
            int px = cx + std::sin(ANGLE * M_PI / 180) * radius;
            int py = cy - std::cos(ANGLE * M_PI / 180) * radius;
            // SDL_Rect test2 = { px,py,10,10 };

             //SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 255, 255, SDL_ALPHA_OPAQUE);
            // SDL_RenderDrawRect(Display::GetRenderer(), &test2);
            // SDL_RenderFillRect(Display::GetRenderer(), &test2);
            WheelCords[i].x = px;
            WheelCords[i].y = py;
        }

        int delta = SDL_GetTicks() - starttick;     //actual time b/w frames

        int avgFPS = 60 / (desiredDelta - delta);  //calculating FPS HERE

        if (delta < desiredDelta) {
            SDL_Delay(desiredDelta - delta);
        }
    }
    else {
        switch (sinner) {
        case 0:
            std::cout << "Treachery\n";
            break;
        case 1:
            std::cout << "Fraud\n";
            break;
        case 2:
            std::cout << "violence\n";
            break;
        case 3:
            std::cout << "hearsay\n";
            break;
        }
    }
    int hiangle = (int)angle;
    hiangle %= 360;
    int pos = hiangle / (360 / 9);
    //std::cout << pos << "\n";
      Display::Present();
   if(angle > 360.00){
       angle -= 360.00;
   }
   
   if (angleoffset != 0.0) {
       angleoffset *= .999;
       if (angleoffset < 0.01) {
           angleoffset = 0.0;
           Game::onStop();
       }      
   }
}


void Game::update() {
    bool used = false;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            found = false;
            do {
                float x = (float) (10 + rand() % 100) / 20.0;
               angleoffset = x;
                if (event.key.keysym.scancode == SDL_SCANCODE_KP_ENTER) {
                    used = false;
                }
            } while (used);
        }
        switch (event.key.keysym.scancode) {

        case SDL_SCANCODE_1:
            //AudioPlayer::PlaySound(AudioManager::Effects["bells"]);
            Mix_PlayChannel(-1, AudioManager::Effects["cool"], 0);
            break;
        case SDL_SCANCODE_2:
            //AudioPlayer::PlaySound(AudioManager::Effects["bells"]);
            Mix_PlayChannel(-1, AudioManager::Effects["bell"], 0);
            break;
        case SDL_SCANCODE_3:
            //AudioPlayer::PlaySound(AudioManager::Effects["bells"]);
            Mix_PlayChannel(-1, AudioManager::Effects["bells"], 0);
            break;
        case SDL_SCANCODE_UP:
            angle += 2.0;
            int hiangle = (int)angle;
            hiangle %= 360;
            int pos = hiangle / (360 / 9);
            //std::cout << pos << "\n";
            break;
        //case SDL_SCANCODE_PAUSE:
        /*    do{
                SDL_PollEvent(&event);
                paused = true;
                avgFPS = 0;
                if (event.key.keysym.scancode == SDL_SCANCODE_KP_ENTER) {
                    paused = false;
                }
            }while(paused);*/
           // break;
        }

    }
}

void Game::run() {
  // AudioPlayer::PlayMusic(AudioManager::SoundTracks["fire"]);
    // Mix_PlayMusic(AudioManager::SoundTracks["fire"], -1);

    while (running) {
        update();
        render();
    }   
}
void Game::WheelStopped() {
    found = true;
    Mix_PlayChannel(-1, AudioManager::Effects["cool"], 0);
    Mix_PlayChannel(-1, AudioManager::Effects["bell"], 0);
    SDL_Delay(2000);
    Mix_PlayChannel(-1, AudioManager::Effects["cool"], 0);
    Mix_PlayChannel(-1, AudioManager::Effects["bell"], 0);
    SDL_Delay(2000);
    Mix_PlayChannel(-1, AudioManager::Effects["cool"], 0);
    Mix_PlayChannel(-1, AudioManager::Effects["bell"], 0);
    
    int hiangle = (int)angle;
    hiangle %= 360;
    int pos = hiangle / (360 / 9);
    //std::cout << pos << "\n";
    sinner = pos;
}

void Game::quit() {
    running = false;
    //AudioManager::Clean();
}

/****************************
STATIC MEMBERS OF CLASS GAME:
*****************************/

