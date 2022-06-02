#include "triangle.h"



triangle::triangle(point* p, int col, int n): polygon(p,col,n)
{
}

void triangle::draw() {
	GP142_lineXY(color, list[0].x, list[0].y, list[1].x, list[1].y, 2);
	GP142_lineXY(color, list[1].x, list[1].y, list[2].x, list[2].y, 2);
	GP142_lineXY(color, list[2].x, list[2].y, list[0].x, list[0].y, 2);
	
}

string triangle::save()
{
	string a = "triangle ";
	a += to_string(list[0].x);
	a += " ";
	a += to_string(list[0].y);
	a += " ";
	a += to_string(list[1].x);
	a += " ";
	a += to_string(list[1].y);
	a += " ";
	a += to_string(list[2].x);
	a += " ";
	a += to_string(list[2].y);
	a += " ";
	a += to_string(color);
	return a;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return ((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}


bool triangle::contain(point p) {
		float A = area(list[0].x, list[0].y, list[1].x, list[1].y, list[2].x, list[2].y);
		float A1 = area(p.x, p.y, list[1].x, list[1].y, list[2].x, list[2].y);
		float A2 = area(list[0].x, list[0].y, p.x, p.y, list[2].x, list[2].y);
		float A3 = area(list[0].x, list[0].y, list[1].x, list[1].y, p.x, p.y);
			if (A == A1 + A2 + A3)
				return true;
			return false;
		
}

void triangle::fill(int c) {

}

triangle::~triangle()
{
}
