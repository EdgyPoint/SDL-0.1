#include "Globals.h"
#include "Application.h"
#include "ModuleSceneCastle.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleSceneCastle::ModuleSceneCastle()
{
	// Background / sky
	background = { 0, 0, 456, 4216 };
	background2 = { 0, 0, 456, 4216 };
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
	LOG("Unloading honda stage");

	fading = false;

	return true;
}

// Update: draw background
update_status ModuleSceneCastle::Update()
{
	// Draw everything --------------------------------------	

	App->render->Blit(graphics, 50, -15, &background, 0.75f); // back of the room
	App->render->Blit(graphics, 50, -15, &background, 0.75f); // back of the room


	if (App->input->keyboard[SDL_SCANCODE_SPACE] && fading == false)
	{
		App->fade->FadeToBlack(this, App->ending, 2.0f);
		fading = true;
	}// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}