#pragma once
#include "polygon.h"
#include <string>
class rectangle :public polygon
{
public:
	rectangle(point*, int, int);
	void draw();
	bool contain(point);
	void fill(int);
	string save();
	
	~rectangle();
};

