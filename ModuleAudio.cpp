#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer\include\SDL_mixer.h"

ModuleAudio::ModuleAudio()
{
	audio[last];
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	if (Mix_Init(MIX_INIT_OGG) == 0)
	{
		LOG("An error has ocurred while initializing the audio: %s", SDL_GetError())
			return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		LOG("An error has ocurred while opening the audio has ocurred: %s", SDL_GetError())
	}

	ModuleAudio::Load("Gunbird OST Trump A.ogg");

	if (Mix_PlayMusic(audio[last], -1) == -1)
	{
		LOG("An error has ocurred while reproducing the audio %s", SDL_GetError())
	}

	return true;
}

bool ModuleAudio::CleanUp()
{
	LOG("Freeing audio");

	Mix_FreeMusic(audio[last]);

	//Mix_FreeMusic();//Free mixer
	Mix_Quit();
	return true;
}

Mix_Music* const ModuleAudio::Load(const char* path)
{
	audio[last] = Mix_LoadMUS(path);
	if (audio[last] == NULL)
	{
		LOG("An error has ocurred when loading the sound: %s", SDL_GetError())
	}

	return audio[last];
}

