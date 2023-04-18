#include "Point.h"
#include <iostream>
#include<ostream>

using std::ostream; 
using std::istream;
using namespace std;

Point::Point()
{
	selected = false;
	occupied = false;/*necessario per evitare che due navi siano a contatto:
						devono esistere punti occupati che non siano navi.*/
}



const bool Point::is_occupied()
{
	return occupied;
}

const bool Point::is_selected()
{
	return selected;
}

 const void  Point::hit()
{
	if (selected)
	{
		cout << "Cella non disponibile" << endl;
	}
	if (!selected)
	{
		selected = true; 
	}
	
}

 const void Point::print()
{
	if(selected)
		cout<< "O";/*caselle mancate*/
	
	if (!selected)
		cout << "-"; /*caselle incognite*/
	
}

 void Point::occupy()
 {
	 occupied = true;
 }
 const bool Point::is_hitted()
 {
	 return false;
 }