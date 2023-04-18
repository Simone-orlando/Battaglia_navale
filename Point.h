#pragma once
#include <ostream>

using std::ostream;

class Point
{
public:
	
	Point();
	const bool is_occupied();
	const bool is_selected();
	virtual const void hit();
	virtual const void print();
	virtual const bool is_hitted();
	void occupy();

protected:
	bool occupied, selected;


};

