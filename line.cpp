#include "line.h"

line::line(bool s, point *cord, int col, int numpoints):openshape(s,cord,col,n) {

}


void line::draw() {
	if(style)
	GP142_lineXY(color, list[0].x, list[0].y, list[1].x, list[1].y,1);

	else {
		float slope = float(list[1].y - list[0].y) / (list[1].x - list[0].x);

		float y_intercept = list[0].y - (slope*(list[0].x));

		if (slope == 0) {
			for (float i = list[0].x; i < list[1].x; i=i+2) {
				GP142_pixelXY(color, i,list[1].y);
			}
		}

		else if (slope < 0 && list[1].x < list[0].x) {
		for (float i = list[1].x; i < list[0].x; i=i+2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);
				
			}
		}

		else if (list[1].x < 0 &&  list[1].y < 0) {
			for (float i = list[1].x; i < list[0].x; i = i + 2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);
			}
		}


		else {
			for (float i = list[0].x; i < list[1].x; i = i + 2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);

			}
		}

	}

}

string line::save()
{
	string a = "line ";
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

bool line::contain(point p) {
	float slope = float(list[1].y - list[0].y) / (list[1].x - list[0].x);

	float y_intercept = list[0].y - (slope*(list[0].x));

	int A = p.y;
	int B = (p.x)*slope + y_intercept;
	if (A == B) {
		return true;
	}

	return false;
}


void line::fill(int c) {
	color = c;
	if(style)
	GP142_lineXY(color, list[0].x, list[0].y, list[1].x, list[1].y, 1);
	else {
		float slope = float(list[1].y - list[0].y) / (list[1].x - list[0].x);

		float y_intercept = list[0].y - (slope*(list[0].x));

		if (slope == 0) {
			for (float i = list[0].x; i < list[1].x; i = i + 2) {
				GP142_pixelXY(color, i, list[1].y);
			}
		}

		else if (slope < 0 && list[1].x < list[0].x) {
			for (float i = list[1].x; i < list[0].x; i = i + 2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);

			}
		}

		else if (list[1].x < 0 && list[1].y < 0) {
			for (float i = list[1].x; i < list[0].x; i = i + 2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);
			}
		}


		else {
			for (float i = list[0].x; i < list[1].x; i = i + 2) {
				GP142_pixelXY(color, i, (slope*i) + y_intercept);

			}
		}
	}

}


line::~line()
{
}
