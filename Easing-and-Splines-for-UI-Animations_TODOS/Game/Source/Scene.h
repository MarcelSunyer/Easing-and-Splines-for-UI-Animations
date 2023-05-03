#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Tweening.h"

struct SDL_Texture;

class BasicPlayer
{
public:
	BasicPlayer()
	{
		x = 0, y = 0;
	}
	~BasicPlayer() {}
	int x, y;
	float speed;
private:
	
};

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:
	SDL_Texture* img;
	

	int example = 1;

	//EXAMPLE 1
	SDL_Texture* bg;
	SDL_Texture* letters;
	SDL_Texture* slider;
	Tween animacionExample;
	int totalTweenings;
	int TiempoAnimacion;
	int AnimacionEasingType;

	
	int font3;

	//EXAMPLE 2
	SDL_Texture* map;
	SDL_Texture* map_2;
	SDL_Texture* sign;
	SDL_Texture* UIelements;
	SDL_Texture* inventory;
	SDL_Texture* panel;
	SDL_Texture* button1;
	SDL_Texture* button2;
	SDL_Texture* button3;

	Tween animaciónCamera;
	Tween animacion_UI_fondo;
	Tween animacion_UI_inventory;
	Tween animacion_UI_BackToTitle;
	Tween animacion_UI_Back;
	Tween animacion_UI_Continue;

	BasicPlayer player1;

	bool menuOpen;
	bool inventoryOpen;
};

#endif // __SCENE_H__