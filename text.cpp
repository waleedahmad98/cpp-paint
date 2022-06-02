#include "text.h"



text::text(int t, string w,point* p ,int col, int num):shape(p, col, num)
{
	words = w;
	tsize = t;
}

void text::draw() {

	GP142_textXY(color, list[0].x, list[0].y, tsize, words.c_str());

}

string text::save()
{
	string a = "text ";
	a += to_string(color);
	a += " ";
	a += to_string(list[0].x);
	a += " ";
	a += to_string(list[0].y);
	a += " ";
	a += words;
	

	return a;
}

text::~text()
{

}

void text::fill(int c) {

}



bool text::contain(point p) {

	if (p.x >= list[0].x && p.x <= list[0].x+20) {
		if (p.y >= list[0].y &&  p.y <= list[0].y+20)
			return true;
	}
	return false;

}