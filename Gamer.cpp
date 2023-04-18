#include "Gamer.h"
#include <iostream>
using namespace std;

void remove_element(int n, Ship ships[], int size);

Gamer::Gamer(World& w) : world(w) // prende il mondo su cui agire
{
	ships = new Ship[n_of_ships];
}
const int Gamer::get_n_of_ships()
{
	return ships_placed;
}

const void Gamer::place_ship(int x, int y, int length, int dir)
{
	/*Fa la stessa cosa di put_ship in world*/
	ships[ships_placed] = *new Ship(length);

	if (!world.put_ship(x, y, length, dir, ships[ships_placed])) delete &ships[ships_placed];

	else ships_placed++;

}

const void Gamer::hit(Point& point)
{
	point.hit();
	for (int i = 0; i < ships_placed; i++)
	{
		cout << "ship sinked="<< ships[i].is_sinked() << endl;
		cout <<"i ="<< i << endl;

		if (ships[i].is_sinked())
		{
			remove_element(i, ships, ships_placed);
			Gamer::ships_placed--;

		}
	}
}

void remove_element(int n, Ship ships[], int size)
{
	
	// shift elements to the left
	for (int i = n; i < size - 1; i++)
	{
		ships[i] = ships[i + 1];
	}

	// decrement size by 1
	size--;

	// delete the last element
	Ship* newArr = new Ship[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = ships[i];
	}

	//delete[] ships;
	ships = newArr;
}