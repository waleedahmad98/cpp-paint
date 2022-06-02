#include "shape.h"



shape::shape(point* p, int col, int num) : color(col), n(num) {
	list = p;
	//for (int i = 0; i < num; i++) {
		//list[i] = p[i];
	//}

}



shape::~shape()
{
}

