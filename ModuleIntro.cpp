#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleIntro.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleIntro::ModuleIntro() : Module()
{
	background = { 0, 0, 240, 1080 };
}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("honda_stage2.png");

	

	return ret;
}

// Load assets
bool ModuleIntro::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");


	fading = false;

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	// Draw everything --------------------------------------	
	
	App->render->Blit(graphics, 50, -15, &background, 0.75f); // back of the room

	if (App->input->keyboard[SDL_SCANCODE_SPACE] && fading == false)
	{
		App->fade->FadeToBlack(this, App->castle, 2.0f);
		fading = true;
	}// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}