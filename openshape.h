#pragma once
#include "shape.h"
#include <string>
class openshape : public shape
{
protected:
	bool style;

public:
	
	openshape(bool, point*, int, int);
	
	bool contain(point);
	void fill(int);

	virtual ~openshape();
};
 
