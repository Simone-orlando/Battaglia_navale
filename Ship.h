#pragma once
#include"Ship_point.h"
#include "Point.h"



class Ship
{
public:
	Ship(int = 1);
	friend class World;
	const bool is_sinked();

private:
	const void insert_point(Point&);
protected:
	int n_points;
	int points;
	Point* ship;
	
};

