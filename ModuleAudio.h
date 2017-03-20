#ifndef _ModuleAudio_H
#define _ModuleAudio_H

#include "Module.h"
#include "Globals.h"

#include "SDL_mixer\include\SDL_mixer.h"

#define MAX_AUDIO 50



class ModuleAudio : public Module

{

public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	Mix_Music* audio[MAX_AUDIO];
	uint last_track = 0;

};

#endif