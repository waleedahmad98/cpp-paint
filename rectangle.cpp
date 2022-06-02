#include "rectangle.h"



rectangle::rectangle(point* p, int col, int n): polygon(p,col,n)
{
}

void rectangle::draw() {
	GP142_lineXY(color, list[0].x, list[0].y, list[0].x, list[1].y, 2);
	GP142_lineXY(color, list[1].x, list[1].y, list[1].x, list[0].y, 2);
	GP142_lineXY(color, list[0].x, list[0].y, list[1].x, list[0].y, 2);
	GP142_lineXY(color, list[1].x, list[1].y, list[0].x, list[1].y, 2);
}

string rectangle::save()
{	
	string a = "rectangle ";
	a += to_string(list[0].x);
	a += " ";
	a += to_string(list[0].y);
	a += " ";
	a += to_string(list[1].x);
	a += " ";
	a += to_string(list[1].y);
	a += " ";
	a += to_string(color);
	return a;
}

bool rectangle::contain(point p) {
	if (p.x > list[0].x && p.x < list[1].x) {
		if (p.y < list[0].y &&  p.y > list[1].y)
			return true;
	}
	return false;


}


void rectangle::fill(int color) {
	/*for (int i = list[0].x; i < list[1].x; i++) {
		GP142_lineXY(color, i, list[0].y, i, list[1].y,1);
	}

	*/

}



rectangle::~rectangle()
{
}
