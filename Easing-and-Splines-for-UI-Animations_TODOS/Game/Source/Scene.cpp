#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"
#include "ModuleFonts.h"
#include <stdio.h>

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	char lookupTable1[] = { "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[�]��!���%&'()*+,-.^0123456789:;<=>?/abcdefghijklmnopqrstuvwxyz �������" };
	
	font3 = app->fonts->Load("Assets/Textures/UI/font1_white_1.png", lookupTable1, 6);
	img = app->tex->Load("Assets/Textures/test.png");

	////////////////////////////
	map = app->tex->Load("Assets/Textures/map.png");
	map_2 = app->tex->Load("Assets/Textures/map_2.png");
	sign = app->tex->Load("Assets/Textures/sign.png");
	inventory = app->tex->Load("Assets/Textures/UI/inventory.png");

	

	player1.x = 300;
	player1.y = 300;
	player1.speed = 3;

	panel = app->tex->Load("Assets/Textures/UI/TitleScreen.png");
	button1 = app->tex->Load("Assets/Textures/UI/BacktoTitle.png");
	button2 = app->tex->Load("Assets/Textures/UI/BackTitle.png");
	button3 = app->tex->Load("Assets/Textures/UI/Continue.png");



	menuOpen = false;
	inventoryOpen = false;
	
	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	
	switch (example)
	{
	
	break;		
	
	case 1:
	{

		if (!menuOpen)
		{

			if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
			{
				player1.x += player1.speed;
			}
			if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			{
				player1.x -= player1.speed;

			}
			if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
			{
				player1.y -= player1.speed;

			}
			if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
			{
				player1.y += player1.speed;

			}
		}

	
		
		if ((player1.x > 500 && player1.x < 580) &&
			(player1.y > 400 && player1.y < 480))
		{
		
		}
		else 
		{
			
		}
		//Dibujo Mapa
		app->render->DrawTexture(map, 100, 30);
		app->render->DrawTexture(map_2, 1600, 30);
		//Dibujo "Collider"
		app->render->DrawTexture(sign, 530, 400);
		SDL_Rect playerRect = { player1.x - 20,player1.y - 60,60,60  };
		app->render->DrawRectangle(playerRect, 255, 255, 255, 180);
			
		float point = animaci�nCamera.GetPoint();

		app->render->camera.x = -point * 300;

		

		if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
		{
			menuOpen = !menuOpen;

		}

		if (menuOpen)
		{
			
			
	

		}
		else 
		{
			
			if (app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
			{
				inventoryOpen = !inventoryOpen;

			}
			
		}


	

		if (inventoryOpen)
		{
		

		}
		else
		{
		

		}

		
		
		
		int offset = 720;

		
		app->render->DrawTexture(inventory, 1280 / 2 - 528 / 2, offset + point * (400 - offset));


		offset = -750;

		app->fonts->DrawText(775, 40, font3, "Press [P] to Pause and [I] ");
		app->fonts->DrawText(775, 40 + 20, font3, "to open Inventory");
		app->fonts->DrawText(775, 40 + 25*2, font3, "Use [Arrows] to move the player");
		app->fonts->DrawText(775, 40 + 25 * 3, font3, "Move to the Sign to move camera");

		//Applicamos al punto que queremos que vaya la textura para hacer la animaci�n de todo el menu

	}
	break;
	
	default:

		break;
	}

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
