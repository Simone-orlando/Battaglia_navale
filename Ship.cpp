#include"Ship.h"
#include <iostream>
using namespace std;

Ship::Ship(int len)
{
	n_points = len;
	points = 0;
	ship = new  Point[n_points];
}

const void Ship::insert_point(Point& point)
{
	ship[points] = point;
	point.print();
	points++;

}

const bool Ship::is_sinked()
{
	for (int i = 0; i < points; i++)
	{

		if (!ship[i].is_hitted())
		{
			return false;
		}
	}
	cout << "il punto è: " << ship[0].is_hitted() << endl;
	return true;
}

