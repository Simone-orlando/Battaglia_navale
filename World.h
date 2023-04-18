#pragma once
#include "Point.h"
#include "Ship_point.h"
#include "Ship.h"


class World
{
	
public:

	World();
	Point& get_point(int, int);
	const void display();
	const bool put_ship(int, int, int, int, Ship&);
	


private:
	static const int size_x = 10, size_y = 10;
	Point* world[size_x][size_y];
	const void set_world();

};

