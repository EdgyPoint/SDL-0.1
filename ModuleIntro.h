#ifndef __MODULESCEINTRO_H__
#define __MODULESCEINTRO_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_rect.h"

struct SDL_Texture;

class ModuleIntro : public Module
{
public:
	ModuleIntro();
	~ModuleIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background_intro;

	bool fading = false;
};

#endif 