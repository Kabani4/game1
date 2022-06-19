#pragma once


#include <SDL.h>
#include <iostream>

class display
{
private:
	int width_win = 640;
	int height_win = 480;
	int FPS = 60;
	
public:
	void INIT();
	void DEINIT(int);
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	SDL_Event ev;
	bool isrunning=true;
	int get_fps();
	
};
