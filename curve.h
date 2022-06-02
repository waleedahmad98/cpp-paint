#pragma once
#include "openshape.h"
#include <string>
class curve : public openshape
{
public:
	curve(bool, point*, int, int);

	void draw();
	bool contain(point);
	
	void fill(int);
	string save();
	~curve();
};

