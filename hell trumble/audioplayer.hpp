#include "SDL_mixer.h"

#define MAX_VOL MIX_MAX_VOLUME
#define MIN_VOL 0

class AudioPlayer{
private:
	//static AudioPlayer* instance;
	/*AudioPlayer();
	~AudioPlayer();*/
public:
	static void Init();
	
	/*static void SetSoundVolume(Mix_Chunk* sound,int volume);
	static void SetMusicVolume(int volume);*/
	
	static void PlaySound(Mix_Chunk* sound);
	static void PlaySound(Mix_Chunk* sound, int duration);
	static void PlayMusic(Mix_Music* music);

	//static void PauseMusic(Mix_Music* music);
	//static void ResumeMusic();
	//static void Destroy();
};


