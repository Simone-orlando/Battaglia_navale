#pragma once
#include "Point.h"
class Ship_point : public Point
{
	
public:

	Ship_point();
	const bool is_hitted();
	const void hit();
	const void print();
	

private:

	bool hitted;

};

