#include "game logic.h"


Display::Display(int index)
{
	index_game = index;
	FPS = 60;
}

Display::Display(int index, int FPS)
{
	index_game = index;
	this->FPS = FPS;
}

void Display::INIT()
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
																								
void Display::DEINIT(int error)																					
{																								
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

int Display::get_fps()
{
	return FPS;
}

int Display::get_width()
{
	return width_win;
}

int Display::get_height()
{
	return height_win;
}

int Display::get_size()
{
	return rock_size + 4*between_rock;
}

void Display::draw_map_game()
{
	SDL_SetRenderDrawColor(ren, 0,0,0,255);	
	while (rock_coord.x+ rock_size + between_rock <=width_win)
	{	
		rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
		SDL_RenderFillRect(ren,&rock);
		rock_coord.x += rock_size+ between_rock;
	}
	rock_coord.x -= rock_size + between_rock;
	rock_coord.y += rock_size + between_rock;
	rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
	while (rock_coord.y+ rock_size + between_rock <= height_win)
	{
		rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_coord.y += rock_size + between_rock;
	}
	rock_coord.y -= rock_size + between_rock;
	rock_coord.x -= rock_size + between_rock;
	rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
	while (rock_coord.x+ rock_size + between_rock >= 0)
	{
		rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_coord.x -= rock_size + between_rock;
	}
	rock_coord.x +=2*( rock_size + between_rock);
	rock_coord.y -= rock_size + between_rock;
	rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
	while (rock_coord.y+ rock_size + between_rock >= 0)
	{
		rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
		SDL_RenderFillRect(ren, &rock);
		rock_coord.y -= rock_size + between_rock;
	}
	rock_coord.x = between_rock;
	rock_coord.y = between_rock;
	rock = { rock_coord.x,rock_coord.y,rock_size,rock_size };
}

void Display::draw_hunter(double coord_x, double coord_y)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	SDL_RenderDrawPoint(ren,coord_x,coord_y);
}

double M_hunter::get_x()
{
	return coord.x;
}

double M_hunter::get_y()
{
	return coord.y;
}

void M_hunter::MoveEvent(int width, int height, int size, int FPS, SDL_Event key_ev)
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
}

void M_hunter::MoveHunter(int width, int height, int size, int FPS)
{

	if (isUpPressed && coord.y - speed / FPS > size && !isDownPressed && !isRightPressed && !isLeftPressed) coord.y = coord.y - speed / FPS;
	if (isDownPressed && coord.y + speed / FPS < height - size && !isUpPressed && !isRightPressed && !isLeftPressed) coord.y = coord.y + speed / FPS;
	if (isLeftPressed && coord.x - speed / FPS > size && !isRightPressed && !isUpPressed && !isDownPressed) coord.x = coord.x - speed / FPS;
	if (isRightPressed && coord.x + speed / FPS < width - size && !isLeftPressed && !isDownPressed && !isUpPressed) coord.x = coord.x + speed / FPS;

	if (isUpPressed && isRightPressed && coord.y - speed / FPS / sqrt(2) > size && coord.x + speed / FPS / sqrt(2) < width - size && !isDownPressed && !isLeftPressed)
	{
		coord.y = coord.y - speed / FPS / sqrt(2);
		coord.x = coord.x + speed / FPS / sqrt(2);
	}

	else if (isUpPressed && isRightPressed && coord.y - speed / FPS  <= size && coord.x + speed / FPS  < width - size && !isDownPressed && !isLeftPressed)
		coord.x = coord.x + speed / FPS;
	else if (isUpPressed && isRightPressed && coord.y - speed / FPS  > size && coord.x + speed / FPS >= width - size && !isDownPressed && !isLeftPressed)
		coord.y = coord.y - speed / FPS;

	if (isUpPressed && isLeftPressed && coord.y - speed / FPS / sqrt(2) > size && coord.x - speed / FPS / sqrt(2) > size && !isDownPressed && !isRightPressed)
	{
		coord.y = coord.y - speed / FPS / sqrt(2);
		coord.x = coord.x - speed / FPS / sqrt(2);
	}

	else if (isUpPressed && isLeftPressed && coord.y - speed / FPS  <= size && coord.x - speed / FPS  > size && !isDownPressed && !isRightPressed)
		coord.x = coord.x - speed / FPS;
	else if (isUpPressed && isLeftPressed && coord.y - speed / FPS > size && coord.x - speed / FPS <= size && !isDownPressed && !isRightPressed)
		coord.y = coord.y - speed / FPS;

	if (isDownPressed && isRightPressed && coord.y + speed / FPS / sqrt(2) < height - size && coord.x + speed / FPS / sqrt(2) < width - size && !isUpPressed && !isLeftPressed)
	{
		coord.y = coord.y + speed / FPS / sqrt(2);
		coord.x = coord.x + speed / FPS / sqrt(2);
	}

	else if (isDownPressed && isRightPressed && coord.y + speed / FPS  >= height - size && coord.x + speed / FPS < width - size && !isUpPressed && !isLeftPressed)
		coord.x = coord.x + speed / FPS;
	else if (isDownPressed && isRightPressed && coord.y + speed / FPS  < height - size && coord.x + speed / FPS  >= width - size && !isUpPressed && !isLeftPressed)
		coord.y = coord.y + speed / FPS;
	

	if (isDownPressed && isLeftPressed && coord.y + speed / FPS / sqrt(2) < height - size && coord.x - speed / FPS / sqrt(2) > size && !isUpPressed && !isRightPressed)
	{
		coord.y = coord.y + speed / FPS / sqrt(2);
		coord.x = coord.x - speed / FPS / sqrt(2);
	}

	else if (isDownPressed && isLeftPressed && coord.y + speed / FPS  >= height - size && coord.x - speed / FPS > size && !isUpPressed && !isRightPressed)
		coord.x = coord.x - speed / FPS;
	else if (isDownPressed && isLeftPressed && coord.y + speed / FPS  < height - size && coord.x - speed / FPS <= size && !isUpPressed && !isRightPressed)
		coord.y = coord.y = coord.y + speed / FPS;


	if (isUpPressed && isDownPressed && isRightPressed && coord.x + speed / FPS < width - size   && !isLeftPressed) coord.x = coord.x + speed / FPS;
	if (isUpPressed && isDownPressed && isLeftPressed && coord.x - speed / FPS > size && !isRightPressed) coord.x = coord.x - speed / FPS;
	if (isRightPressed && isLeftPressed && isUpPressed && coord.y - speed / FPS > size && !isDownPressed) coord.y = coord.y - speed / FPS;
	if (isRightPressed && isLeftPressed && isDownPressed && coord.y + speed / FPS < height - size && !isUpPressed) coord.y = coord.y + speed / FPS;

}

Button::Button(int width, int height)
{
	isPressed = false;
	this->width = width;
	this->height = height;
	button.w = width;
	button.h = height;
	this->coord_left_up_angle.x = 0;
	this->coord_left_up_angle.y = 0;
	button.x = this->coord_left_up_angle.x;
	button.y = this->coord_left_up_angle.y;
	this->coord_right_down_angle.x = this->coord_left_up_angle.x + width;
	this->coord_right_down_angle.y = this->coord_left_up_angle.y + height;
}

Button::Button(int width, int height, int x, int y)
{
	isPressed = false;
	this->width = width;
	this->height = height;
	button.w = width;
	button.h = height;
	this->coord_left_up_angle.x = x;
	this->coord_left_up_angle.y = y;
	button.x = this->coord_left_up_angle.x;
	button.y = this->coord_left_up_angle.y;
	this->coord_right_down_angle.x = this->coord_left_up_angle.x + width;
	this->coord_right_down_angle.y = this->coord_left_up_angle.y + height;
}

void Button::Draw_button(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	button.x = coord_left_up_angle.x;
	button.y = coord_left_up_angle.y;
	SDL_RenderFillRect(ren, &button);
}

void Button::SetCoord(int x, int y)
{
	coord_left_up_angle.x = x;
	coord_left_up_angle.y = y;
	coord_right_down_angle.x = coord_left_up_angle.x + width;
	coord_right_down_angle.y = coord_left_up_angle.y + height;
}
