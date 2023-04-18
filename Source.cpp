#include<iostream>
#include"Point.h"
#include"World.h"
#include"Ship_point.h"
#include"Gamer.h"
using namespace std;

int main()
{
	World world;
	Gamer player1(world);
	player1.place_ship(1, 4, 3, 1);
	player1.place_ship(3, 5, 5, 0);
	player1.place_ship(0, 0, 3, 0);
	player1.hit(world.get_point(1, 4));
	player1.hit(world.get_point(2, 4));
	player1.hit(world.get_point(3, 4));
	cout << player1.get_n_of_ships()<<endl;
	world.display();


return 0;
}
