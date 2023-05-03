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
	char lookupTable1[] = { "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[£]çç€!ççç%&'()*+,-.^0123456789:;<=>?/abcdefghijklmnopqrstuvwxyz ççççççç" };
	
	font3 = app->fonts->Load("Assets/Textures/UI/font1_white_1.png", lookupTable1, 6);
	img = app->tex->Load("Assets/Textures/test.png");

	////////////////////////////
	map = app->tex->Load("Assets/Textures/map.png");
	map_2 = app->tex->Load("Assets/Textures/map_2.png");
	sign = app->tex->Load("Assets/Textures/sign.png");
	inventory = app->tex->Load("Assets/Textures/UI/inventory.png");

	//TODO 3: Set and add a tween to the camera

	player1.x = 300;
	player1.y = 300;
	player1.speed = 3;

	panel = app->tex->Load("Assets/Textures/UI/TitleScreen.png");
	button1 = app->tex->Load("Assets/Textures/UI/BacktoTitle.png");
	button2 = app->tex->Load("Assets/Textures/UI/BackTitle.png");
	button3 = app->tex->Load("Assets/Textures/UI/Continue.png");

	//TODO 3: Set and add a tween to the inventory

	//TODO 3: Set and add a tween for the all the Menu

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

		if (!menuOpen) animaciónCamera.Step(2, false);
		//"Collider"
		if ((player1.x > 500 && player1.x < 580) &&
			(player1.y > 400 && player1.y < 480))
		{
			//TODO 4: Forward the camera
		}
		else 
		{
			//TODO 4: Backward the camera
		}

		//Dibujo Mapa
		app->render->DrawTexture(map, 100, 30);
		app->render->DrawTexture(map_2, 1600, 30);
		//Dibujo "Collider"
		app->render->DrawTexture(sign, 530, 400);
		SDL_Rect playerRect = { player1.x - 20,player1.y - 60,60,60  };
		app->render->DrawRectangle(playerRect, 255, 255, 255, 180);
			
		//Set the camerea to a point
		float point = animaciónCamera.GetPoint();
		app->render->camera.x = -point * 300;

		if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
		{
			menuOpen = !menuOpen;
		}

		if (menuOpen)
		{
			//TODO 4: Forward the Menu
		}
		else 
		{
			//TODO 4:Backward the Menu

			if (app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
			{
				inventoryOpen = !inventoryOpen;
			}
			
		}

		//Reset de la animación
		animacion_UI_inventory.Step(1, false);

		if (inventoryOpen)
		{
			//TODO 4: Forward the Inventory
		}
		else
		{
			//TODO 4: Backward the Inventory
		}

		//Resetea todas las animaciones
		animacion_UI_fondo.Step(1, false);
		animacion_UI_BackToTitle.Step(1, false);
		animacion_UI_Back.Step(1, false);
		animacion_UI_Continue.Step(1, false);

		
		
		int offset = 720;

		point = animacion_UI_inventory.GetPoint();
		app->render->DrawTexture(inventory, 1280 / 2 - 528 / 2, offset + point * (400 - offset));


		offset = -750;

		app->fonts->DrawText(775, 40, font3, "Press [P] to Pause and [I] ");
		app->fonts->DrawText(775, 40 + 20, font3, "to open Inventory");
		app->fonts->DrawText(775, 40 + 25*2, font3, "Use [Arrows] to move the player");
		app->fonts->DrawText(775, 40 + 25 * 3, font3, "Move to the Sign to move camera");

		//Applicamos al punto que queremos que vaya la textura para hacer la animación de todo el menu
		
		//TODO 5: Set a concret point to the animation and draw the texture

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
