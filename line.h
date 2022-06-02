#pragma once
#include "openshape.h"
#include <string>

class line : public openshape
{
public:
	line(bool s, point*, int col, int numpoints);
	void fill(int);
	void draw();
	bool contain(point);
	
	
	string save();
	~line();
};

