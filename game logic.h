#pragma once

#include <SDL.h>
#include <iostream>
#include "Helping_instruments.h"
#include <vector>
#include <ctime>

static bool GameLifetime = true;
static bool RunGame = true;
static int Frame_to_spawn_mushroom = 60;
static int original_frame = 0;
static int mushroom_counter = 0;
static int Index_window = 0;

class MAIN_WINDOW
{
private:
	int width_win = 640;
	int height_win = 466;
public:
	void INIT();
	void DEINIT(int);
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	int get_width();
	int get_height();
};

class Display
{
private:
	int FPS;
	int index_game; // индекс экрана
	int rock_size = 27;
	int between_rock = 2;
	Coord_int rock_coord{ between_rock, between_rock };

public:
	Display(int);
	Display(int, int);
	SDL_Event ev;
	SDL_Rect rock = {rock_coord.x,rock_coord.y,rock_size,rock_size};
	int get_fps();
	int get_size();
	void draw_map_game(SDL_Renderer*, int width_win, int height_win);
	void draw_hunter(SDL_Renderer*, double, double);
};

class Game_object
{

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
	void MoveEvent(int,int,int,int,SDL_Event, bool&);
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
	Button(int width, int height);
	Button(int, int, int, int);
	void Draw_button(SDL_Renderer*, int red, int green, int blue, int alfa);
	void SetCoord(int x, int y);
	int GetWidth();
	int GetHeight();
	bool Button_click(SDL_Event);
};

class Mushroom
{
private:
	int timer_of_life;
	Coord_double coords;
public:
	double get_x();
	double get_y();
	friend void Add_mush(double,double,std::vector<Mushroom*>*,int,int,int);
	void Draw_mush(SDL_Renderer*);
	void Delete_mush(double, double, std::vector<Mushroom*>*);
	Mushroom();
	Mushroom(double,double);
};