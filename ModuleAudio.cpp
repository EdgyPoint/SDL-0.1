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

	//Mix_FreeMusic();//Free mixer
	Mix_Quit();
	return true;
}

Mix_Music* const ModuleAudio::Load(const char* path)
{
	Mix_Music* test_audio = Mix_LoadMUS(path);
	if (test_audio == nullptr)
	{
		LOG("Failed to load audio track at %s", path);
	}
	else
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		Mix_PlayMusic(App->audio->audio[last_track], -1);
	}

	audio[last_track++] = test_audio;
	if (last_track >= MAX_AUDIO)
	{
		LOG("Audio overflow");
		last_track = 0;
	}

	return test_audio;
}

