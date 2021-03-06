#include "Globals.h"
#include "Application.h"
#include "ModuleSceneCastle.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadetoBlack.h"
#include "ModuleIntro.h"
#include "SDL/include/SDL.h"

ModuleSceneCastle::ModuleSceneCastle()
{
	// Background / sky
	background_castle = { 0, 0, 228, 2108 };
}
ModuleSceneCastle:: ~ModuleSceneCastle()
{}

// Load assets
bool ModuleSceneCastle::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Castle_Background.png");

	return ret;
}

// Load assets
bool ModuleSceneCastle::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading castle stage");

	fading = false;

	return true;
}

// Update: draw background
update_status ModuleSceneCastle::Update()
{
	// Draw everything --------------------------------------	

	App->render->Blit(graphics, 0, -1788, &background_castle, 0.75f); // back of the room


	if (App->input->keyboard[SDL_SCANCODE_SPACE] && fading == false)
	{
		App->fading->FadeToBlack(this, App->intro, 2.0f);
		fading = true;
	}// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}