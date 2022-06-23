#include "Helping_instruments.h"

Coord_int::Coord_int(int x = 0, int y = 0)
{
	this->x = x;
	this->y = y;
}

Coord_int::Coord_int()
{
	this->x = 0;
	this->y = 0;
}

Coord_double::Coord_double(double x, double y)
{
	this->x = x;
	this->y = y;
}

Coord_double::Coord_double()
{
	this->x = 0;
	this->y = 0;
}
