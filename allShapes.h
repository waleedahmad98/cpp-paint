#pragma once
#include "shape.h"

class allShapes
{
	vector<shape*> allshapes;
	int totalShapes;

public:
	allShapes();
	int getsize();
	void addshape(shape* obj);
	void savefile();
	vector<shape*>& getvector();

	~allShapes();
};

