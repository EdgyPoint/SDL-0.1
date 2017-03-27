#ifndef __ModuleSceneCastle_H__
#define __ModuleSceneCastle_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_rect.h"

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
	SDL_Rect background_castle;
	bool fading = false;
};




#endif //__ModuleSceneCastle_H__