#include "circle.h"
#include <cmath>
#include <fstream>

circle::circle(point* cen, float rad, int col, int num) :shape(cen, col, num)
{
	radius = rad;
}


void circle::draw(){
	double PI = 3.1415926535;
	double i, angle, x1, y1, x2, y2;

	for (i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = radius * cos(angle * PI / 180);
		y1 = radius * sin(angle * PI / 180);
		x2 = radius * cos((angle + 0.1) * PI / 180);
		y2 = radius * sin((angle + 0.1) * PI / 180);
		GP142_lineXY(color, list[0].x + x1, list[0].y + y1, list[0].x + x2, list[0].y + y2, 2);
	}
}

string circle::save() {
	string a = "circle ";
	a += to_string(list[0].x);
	a += " ";
	a += to_string(list[0].y);
	a += " ";
	a += to_string(radius);
	a += " ";
	a += to_string(color);

	return a;


}

void circle::fill(int c) {
	//GP142_circleXY(c, list[0].x, list[0].y, radius - 1);
}

bool circle::contain(point p) {
	float d1 = p.x - list[0].x;
	float d2 = p.y - list[0].y;

	d1 = d1 * d1;
	d2 = d2 * d2;
	int D = d1 + d2;
	D = pow(D , 0.5);
	if (D < radius) {
		return true;
	}

	return false;
}



circle::~circle()
{
}
