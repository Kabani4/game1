#pragma once


#include <SDL.h>
#include <iostream>

class Display
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
	int get_width();
	int get_height();
	int get_size();
	void draw_map_game();
	void draw_hunter(double cord_x, double cord_y);
};

class M_hunter
{
private:
	double cord_x = 200;
	double cord_y = 200;
	double speed = 200;
	bool isUpPressed = false;
	bool isDownPressed = false;
	bool isLeftPressed = false;
	bool isRightPressed = false;
public:
	double get_x();
	double get_y();
	void MoveEvent(int,int,int,int,SDL_Event);
	void MoveHunter(int, int, int, int);
};
