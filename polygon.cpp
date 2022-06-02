#include "polygon.h"


polygon::polygon(point* p, int col, int n):shape(p,col,n) {

}

void polygon::draw() {
	for (int i = 0; i < n ; i++) {
		GP142_lineXY(color, list[i].x, list[i].y, list[i + 1].x, list[i + 1].y, 2);
	}

}

void polygon::fill(int col) {


}

string polygon::save()
{
	string a = "polygon ";
	a += to_string(n);
	a += " ";
	a += to_string(color);
	a += " ";
	for (int i = 0; i < n; i++) {
		a += to_string(list[i].x);
		a += " ";
		a += to_string(list[i].y);
		a += " ";
		
	}
	
	return a;
	
	
}

bool polygon::contain(point p) {
		int    in = 0;  
		for (int i = 0; i < n; i++) {    
			if (((list[i].y <= p.y) && (list[i + 1].y > p.y))  || ((list[i].y > p.y) && (list[i + 1].y <= p.y))) { 
				
				float vt = (float)(p.y - list[i].y) / (list[i + 1].y - list[i].y);
				if (p.x < list[i].x + vt * (list[i + 1].x - list[i].x))
					++in;  
			}
		}
		if ((in & 1) == 1)
			return true;
		return false;
}


polygon::~polygon() {

}
