#include "game logic.h"


void display::INIT()
{

	if (SDL_Init(SDL_INIT_VIDEO != 0))
	{
		printf("Couldn't init video. ERROR:%s", SDL_GetError());
		system("pause");
		DEINIT(1);
	}

	win = SDL_CreateWindow("Mushroom Hunter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_win, height_win,SDL_WINDOW_SHOWN );
	if (win == NULL)
	{
		printf("Couldn't create window. ERROR:%s", SDL_GetError());
		system("pause");																		
		DEINIT(1);																				
	}																							
																								
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)																			
	{																							
		printf("Couldn't create renderer. ERROR:%s", SDL_GetError());								
		system("pause");																		
		DEINIT(1);																				
	}																							
}																								
																								
void display::DEINIT(int error)																					
{																								
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

int display::get_fps()
{
	return FPS;
}

int display::get_width()
{
	return width_win;
}

int display::get_height()
{
	return height_win;
}

int display::get_size()
{
	return rock_size;
}

void display::draw_map_game()
{
	SDL_SetRenderDrawColor(ren, 0,0,0,255);	
	while (rock_x+ rock_size + between_rock <=width_win)
	{	
		rock = { rock_x,rock_y,rock_size,rock_size };
		SDL_RenderFillRect(ren,&rock);
		rock_x += rock_size+ between_rock;
	}
	rock_x -= rock_size + between_rock;
	rock_y += rock_size + between_rock;
	rock = { rock_x,rock_y,rock_size,rock_size };
	while (rock_y+ rock_size + between_rock <= height_win)
	{
		rock = { rock_x,rock_y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_y += rock_size + between_rock;
	}
	rock_y -= rock_size + between_rock;
	rock_x -= rock_size + between_rock;
	rock = { rock_x,rock_y,rock_size,rock_size };
	while (rock_x+ rock_size + between_rock >= 0)
	{
		rock = { rock_x,rock_y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_x -= rock_size + between_rock;
	}
	rock_x +=2*( rock_size + between_rock);
	rock_y -= rock_size + between_rock;
	rock = { rock_x,rock_y,rock_size,rock_size };
	while (rock_y+ rock_size + between_rock >= 0)
	{
		rock = { rock_x,rock_y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_y -= rock_size + between_rock;
	}
	rock_x = between_rock;
	rock_y = between_rock;
	rock = { rock_x,rock_y,rock_size,rock_size };
}

void display::draw_hunter(double cord_x, double cord_y)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	SDL_RenderDrawPoint(ren,cord_x,cord_y);
}

double m_hunter::get_x()
{
	return cord_x;
}

double m_hunter::get_y()
{
	return cord_y;
}

void m_hunter::move(int width, int height, int size, int FPS, SDL_Event key_ev)
{
	
		switch (key_ev.type)
		{
		case (SDL_KEYDOWN):
			switch (key_ev.key.keysym.scancode)
			{
			case SDL_SCANCODE_UP:
				isUpPressed = true;
				break;
			case SDL_SCANCODE_DOWN:
				isDownPressed = true;
				break;
			case SDL_SCANCODE_LEFT:
				isLeftPressed = true;
				break;
			case SDL_SCANCODE_RIGHT:
				isRightPressed = true;
				break;
			}
			break;
			
			case (SDL_KEYUP):
			switch (key_ev.key.keysym.scancode)
			{
			case SDL_SCANCODE_UP:
				isUpPressed = false;
				break;
			case SDL_SCANCODE_DOWN:
				isDownPressed = false;
				break;
			case SDL_SCANCODE_LEFT:
				isLeftPressed = false;
				break;
			case SDL_SCANCODE_RIGHT:
				isRightPressed = false;
				break;
			}
			break;
		}
		
	if (isUpPressed &&  cord_y - speed / FPS >=size) cord_y = cord_y - speed / FPS;
	if (isDownPressed  && cord_y + speed / FPS<=height-size) cord_y = cord_y + speed / FPS;
	if (isLeftPressed  && cord_x - speed / FPS>=size) cord_x = cord_x - speed / FPS;
	if (isRightPressed  && cord_x + speed / FPS<=width-size) cord_x = cord_x + speed / FPS;
}
