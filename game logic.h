#pragma once


#include <SDL.h>
#include <iostream>

class display
{
private:
	int width_win = 640;
	int height_win = 466;
	int FPS = 60;
	int index_game = 0;// индекс экрана
	int rock_size = 27;
	int between_rock = 2;
	int rock_x = between_rock;
	int rock_y = between_rock;
	
public:
	void INIT();
	void DEINIT(int);
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	SDL_Event ev;
	SDL_Rect rock = {rock_x,rock_y,rock_size,rock_size};
	bool isrunning=true;
	int get_fps();
	void draw_map_game();
	
};
