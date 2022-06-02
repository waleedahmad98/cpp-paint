#pragma once
#include "shape.h"
#include <string>
class circle :	public shape
{
	float radius;
public:
	circle(point*, float, int, int);
	void draw();
	bool contain(point);
	void fill(int);
	
	string save();
	~circle();
};

