#include "allShapes.h"
#include <fstream>
#include <string>

allShapes::allShapes()
{
	totalShapes = 0;
}

void allShapes::addshape(shape* obj) {
	allshapes.push_back(obj);
	totalShapes++;
}

vector<shape*>& allShapes::getvector() {
	return allshapes;
}

int allShapes::getsize() {
	return allshapes.size();
}



void allShapes::savefile() {
	ofstream out;
	
	out.open("paint.txt");
	if (out) {
		out << totalShapes << endl;
		for (int i = 0; i<int(allshapes.size()); i++) {
			out << allshapes[i]->save();
			out << endl;
		}
	}
}

allShapes::~allShapes()
{
}
