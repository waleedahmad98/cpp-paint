#pragma once
#include "shape.h"
#include <string>
class text : public shape
{
	string words;
	int tsize;
public:
	text(int , string,point* p, int, int);
	void draw();
	string save();
	bool contain(point);
	void fill(int);
	
	~text();
};

