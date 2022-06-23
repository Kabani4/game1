#pragma once

#include <SDL.h>
#include <iostream>
#include "Helping_instruments.h"

static bool GameLifetime = true;

class Display
{
private:
	int width_win = 640;
	int height_win = 466;
	int FPS;
	int index_game; // индекс экрана
	int rock_size = 27;
	int between_rock = 2;
	Coord_int rock_coord{ between_rock, between_rock };

public:
	Display(int);
	Display(int, int);
	void INIT();
	void DEINIT(int);
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	SDL_Event ev;
	SDL_Rect rock = {rock_coord.x,rock_coord.y,rock_size,rock_size};
	int get_fps();
	int get_width();
	int get_height();
	int get_size();
	void draw_map_game();
	void draw_hunter(double, double);
};

class M_hunter
{
private:
	Coord_double coord{200, 200};
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

class Button
{
private:
	int width;
	int height;
	bool isPressed; //Переменная состояния, если нажата True. иначе False. Изначально кнопка всегда имеет состояние False
	Coord_int coord_left_up_angle; //Координаты левого верхнего угла кнопки
	Coord_int coord_right_down_angle; //Координаты правого нижнего угла кнопки
	SDL_Rect button;

public:
	Button(int, int);
	Button(int, int, int, int);
	void Draw_button(SDL_Renderer*);
	void SetCoord(int, int);
};