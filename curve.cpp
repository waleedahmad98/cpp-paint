#include "curve.h"

curve::curve(bool s, point* p, int col, int num) :openshape(s, p, col, num) {}


void curve::draw() {
	for (int i = 0; i < n - 1; i++) {
		GP142_lineXY(color, list[i].x, list[i].y, list[i + 1].x, list[i + 1].y, 1);
	}
}

string curve::save()
{
		string a = "curve ";
		a += to_string(n);
		a += " ";
		a += to_string(color);
		a += " ";
		for (int i = 0; i < n-1; i++) {
			a += to_string(list[i].x);
			a += " ";
			a += to_string(list[i].y);
			a += " ";
			
		}
		
		

		return a;


}
	




bool curve::contain(point p) {

	for (int i = 0; i < n-1; i++) {
		float slope = float(list[i+1].y - list[i].y) / (list[i+1].x - list[i].x);

		float y_intercept = list[i].y - (slope*(list[i].x));

		int A = p.y;
		int B = (p.x)*slope + y_intercept;
		if (A == B) {
			return true;
		}

	}

	return false;
	
}


void curve::fill(int c) {
	for (int i = 0; i < n-1 ; i++) {
		GP142_lineXY(c, list[i].x, list[i].y, list[i + 1].x, list[i + 1].y, 1);
	}

}

curve::~curve()
{
}
