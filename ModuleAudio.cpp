#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer\include\SDL_mixer.h"

ModuleAudio::ModuleAudio()
{
	for (int i = 0; i < MAX_AUDIO; i++) { audio[i] = nullptr; }
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	LOG("Init Audiolibrary");
	bool ret = true;

	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Audio lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleAudio::CleanUp()
{
	LOG("Freeing audio");

	for (int i = 0; i <= last_track; i++) {Mix_FreeMusic (audio[i]); }

	//4Mix_FreeMusic();//Free mixer
	Mix_Quit();
	return true;
}