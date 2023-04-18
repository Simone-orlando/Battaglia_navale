#pragma once
#include"Point.h"
#include"World.h"
#include"Ship_point.h"
#include "Ship.h"
class Gamer
{
public:
	
	Gamer(World&);
	const void place_ship(int =0, int =0, int=1, int=0);
	//place_ship prende come argomenti ((x,y), lunghezza, direzione)
	const int get_n_of_ships();
	const void sinked(Ship&);
	const void hit(Point&);

private:

	int n_of_ships= 5; int ships_placed = 0;
	World& world;
	Ship* ships;


};

