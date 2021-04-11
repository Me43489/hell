#include "SDL_mixer.h"
#include "SDL.h"
#include "audioplayer.hpp"
#include <iostream>

#define MAX_VOL MIX_MAX_VOLUME
#define MIN_VOL 0

/*class AudioPlayer {
private:

public:
	static void SetSoundVolume(Mix_Chunk* sound, int volume);
	static void SetMusicVolume(Mix_Music* music);
	static void PlaySound(Mix_Chunk* sound);
	static void PlaySound(Mix_Chunk* sound, int duration);
	AudioPlayer();
	~AudioPlayer();
}*/

void AudioPlayer::Init() {
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) < 0) {
		std::cout << "Audio player failed";
		exit(1);
	}
}

/*void AudioPlayer::SetSoundVolume(Mix_Chunk* sound, int volume) {
	Mix_VolumeChunk(sound, volume);
}

void AudioPlayer::SetMusicVolume(int volume) {
	Mix_VolumeMusic(volume);
}*/

void AudioPlayer::PlaySound(Mix_Chunk* sound) {
	Mix_PlayChannel(-1,sound, 0);
}

void AudioPlayer::PlaySound(Mix_Chunk* sound, int duration) {
	Mix_PlayChannelTimed(-1, sound, 0,duration);
}

void AudioPlayer::PlayMusic(Mix_Music* music) {
	Mix_PlayMusic(music, -1);
}



/***********************
		Statics 
************************/
//AudioPlayer* AudioPlayer::instance;


