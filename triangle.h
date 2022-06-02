#pragma once
#include "polygon.h"
#include <string>
class triangle :public polygon
{
public:
	triangle(point*, int, int);
	void draw();
	string save();
	bool contain(point);
	void fill(int);

	~triangle();
};

