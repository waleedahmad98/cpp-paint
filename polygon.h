#pragma once
#include "shape.h"
#include <string>
class polygon :public shape {


public:
	
	polygon(point*, int , int);
	void draw();
	
	string save();
	bool contain(point);
	void fill(int);
	
	~polygon();

};