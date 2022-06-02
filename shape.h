#pragma once
#include <iostream>
#include "GP142.h"
#include <vector>
#include <string>
using namespace std;

struct point {
	int x;
	int y;
};

class shape {
protected:
	point* list;
	int color;
	const int n;

public:
	
	shape::shape(point*, int , int); // point list, color, numpoints
	virtual string save()=0;

	virtual ~shape();
	virtual void draw() = 0;
	virtual void fill(int)=0;
	virtual bool contain(point) = 0;


};
