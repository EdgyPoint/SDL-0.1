#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{

}

ModuleAudio::~ModuleAudio()
{

}

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

	ModuleAudio::Load("music.ogg");

		if (Mix_PlayMusic(audio[last], -1) == -1)
		{
			LOG("An error has ocurred while reproducing the audio %s", SDL_GetError())
		}
	
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
bool ModuleAudio::CleanUp()
{
	Mix_CloseAudio();
	Mix_FreeMusic(audio[last]);

	return true;
}
