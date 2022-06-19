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
