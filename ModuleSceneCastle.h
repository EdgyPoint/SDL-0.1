#ifndef __ModuleSceneCastle_H__
#define __ModuleSceneCastle_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneCastle : public Module
{
public:
	ModuleSceneCastle();
	~ModuleSceneCastle();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background2;
	SDL_Rect background;
	bool fading = false;
};




#endif //__ModuleSceneCastle_H__