#include "Ship_point.h"
#include<iostream>
#include "Ship.h"

using namespace std;

Ship_point::Ship_point():Point()
{
	hitted = false; //indica colpito o no 
	occupied = true; //indica occupato da una nave
					 //oppure adiacente a una nave
}

const bool Ship_point::is_hitted()
{
	return hitted; 
}

const void Ship_point::hit()
{
	if (Point::selected)
	{
		cout << "Cella non disponibile" << endl;
	}
	if (!Point::selected)
	{
		Ship_point::Point::selected = true;
	}
	hitted = true;

}

const void Ship_point::print()
{
	if (hitted)
		cout << "X";/*caselle mancate*/

	//else if (!selected)
		//cout << "-"; /*caselle incognite*/
	else cout << "@"; //solo per vedere se funge.


}
