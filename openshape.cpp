#include "openshape.h"

openshape::openshape(bool s, point* p, int col, int num) : shape(p, col, num) {
	style = s;
}


bool openshape::contain(point p) {
	return true;

}

void openshape::fill(int c) {

}


openshape::~openshape()
{
}
