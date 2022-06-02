#include <iostream>
#include "GP142.h"
#include <stdio.h>
#include <math.h>
#include "allShapes.h"
#include "openshape.h"
#include "line.h"
#include "circle.h"
#include "text.h"
#include "polygon.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"
#include "curve.h"
#include <vector>
#include <fstream>
#include <Windows.h>
#include "shape.h"
#include "GP142.H"
#define PI 3.1415926535
#define ANIMATE_MSG "Select \"Animate\"\nOn the \"Run\" Menu"
#define TEXT_SIZE 20



void draw_line(int x1, int y1, int x2, int y2, int color=WHITE, int width=1){
	GP142_lineXY (color,x1,y1,x2,y2,width);
}

void draw_circle(int x, int y, int radius, int color=1){
	GP142_circleXY(color, x, y, radius);
}

void fill(int x, int y, int bg, int color) {
	if (get_pixel(x, y) != bg)
		return;
	else {
		GP142_pixelXY(color, x, y);
		fill(x, y + 1, bg, color);
		fill(x+1, y + 1, bg, color);
		fill(x+1, y, bg, color);
		fill(x, y + 1, bg, color);
		fill(x+1, y - 1, bg, color);
		fill(x, y - 1, bg, color);
		fill(x-1, y - 1, bg, color);
		fill(x-1, y + 1, bg, color);
	}


}

void border() {

	for (int i = -800; i < -700; i++) {
		GP142_lineXY(12, i, 420, i, -420, 1);
	}
	for (int i = -700; i < 600; i++) {
		GP142_lineXY(12, i, 420, i, 390, 1);
		GP142_lineXY(12, i, -420, i, -389, 1);
	}
	for (int i = 600; i < 645; i++) {
		GP142_lineXY(12, i, 420, i, -420, 1);
	}

	for (int i = 645; i < 750; i++) {
		GP142_lineXY(12, i, 420, i, 345, 1);
		GP142_lineXY(12, i, 20, i, 10, 1);
		GP142_lineXY(12, i, -310, i, -420, 1);
	}

	for (int i = 645; i < 680; i++) {
		GP142_lineXY(12, i, 20, i, -310, 1);
	}

	for (int i = 750; i < 800; i++) {
		GP142_lineXY(12, i, 420, i, -420, 1);
	}


}

void displayMenu() {
	GP142_printfXY(WHITE, -150, 350, 25, "WELCOME TO PAINT");
	for (int i = -800; i < 800; i++) {
		GP142_lineXY(12, i, 420, i, -420, 1);
	}

	for (int i = -700; i < 600; i++) {
		GP142_lineXY(1, i, 390, i, -390, 1);
	}

	
	

	
}
void displayToolbox() { // only display
	
	
	for (int i = 645; i < 750; i++) {
		GP142_lineXY(20, i, 345, i, 20, 1);
	}
	GP142_printfXY(WHITE, 670, 320, 10, "TOOLBOX");

	GP142_rectangleXY(1, 700, 298, 730, 268, 2);
	GP142_circleXY(1, 715, 283, 5); 

	GP142_rectangleXY(1, 660, 298, 690, 268, 2); //curve
	GP142_printfXY(WHITE, 668, 272, 25, "(");

	GP142_rectangleXY(1, 700, 260, 730, 230, 2);
	GP142_lineXY(1, 705, 235, 725, 255, 2);

	GP142_rectangleXY(1, 660, 260, 690, 230, 2); //dotted
	GP142_lineXY(1, 665, 235, 670, 240, 2);
	GP142_lineXY(1, 672, 242, 677, 247, 2);
	GP142_lineXY(1, 679, 249, 684, 254, 2);

	

	GP142_rectangleXY(1, 700, 222, 730, 192, 2);
	GP142_printfXY(WHITE, 710, 196, 20, "T");

	GP142_rectangleXY(1, 660, 222, 690, 192, 2); //fill tool
	GP142_printfXY(WHITE, 668, 155, 20, "B");

	GP142_rectangleXY(1, 700, 184, 730, 154, 2);
	GP142_lineXY(1, 704, 175, 724, 175, 2);
	GP142_lineXY(1, 704, 165, 724, 165, 2);
	GP142_lineXY(1, 705, 175, 705, 165, 2);
	GP142_lineXY(1, 724, 175, 724, 165, 2);

	GP142_rectangleXY(1, 660, 184, 690, 154, 2); 
	GP142_printfXY(WHITE, 668, 195, 20, "E");

	GP142_rectangleXY(1, 700, 146, 730, 116, 2);
	GP142_lineXY(1, 704, 122, 715, 140, 2);
	GP142_lineXY(1, 715, 140, 726, 122, 2);
	GP142_lineXY(1, 726, 122, 704, 122, 2);
	

	GP142_rectangleXY(1, 660, 146, 690, 116, 2);// save board
	GP142_rectangleXY(1, 664, 140, 686, 120, 2);
	GP142_rectangleXY(1, 668, 130, 682, 120, 2);


	GP142_rectangleXY(1, 700, 108, 730, 78, 2);
	GP142_lineXY(1, 704, 100, 704, 85, 2);
	GP142_lineXY(1, 704, 85, 725, 85, 2);
	GP142_lineXY(1, 704, 100, 715, 100, 2);
	GP142_lineXY(1, 715, 100, 725, 85, 2);

	GP142_rectangleXY(1, 660, 108, 690, 78, 2); // load board
	GP142_rectangleXY(1, 664, 102, 686, 82, 2);
	GP142_printfXY(WHITE, 670,83, 15, "L");

	GP142_rectangleXY(1, 700, 70, 730, 40, 2);
	GP142_printfXY(WHITE, 705, 45, 10, "CLR");
}

void displayPalette() { // only display

	GP142_rectangleXY(20, 700, -10, 730, -290, 40);
	GP142_printfXY(WHITE, 690, -20, 10, "PALETTE");

	GP142_rectangleXY(2, 710, -50, 720, -60, 20);
	

	GP142_rectangleXY(3, 710, -88, 720, -98, 20);
	

	GP142_rectangleXY(4, 710, -126, 720, -136, 20);
	

	GP142_rectangleXY(5, 710, -164, 720, -174, 20);

	GP142_rectangleXY(13, 710, -202, 720, -212, 20);

	GP142_rectangleXY(1, 710, -240, 720, -250, 20);

	GP142_rectangleXY(0, 710, -278, 720, -288, 20);
}

void highlightSelection(int x, int y, int w, int z) {
	
	GP142_rectangleXY(5, x, y, w, z, 2);
}

int makeSelection(int mouse_x, int mouse_y) {
	int temp = 0;
	if (mouse_y < 326 && mouse_y > -311) // if mouse is in canvas
		if (mouse_x > -430 && mouse_x < 366)
			temp = 0;

		else if (mouse_x > 660 && mouse_x < 730) {
			if (mouse_y < 298 && mouse_y > 268) { // for each selection an if will work - BOX 1
				displayToolbox();
				temp = 1;
				highlightSelection(700, 298, 730, 268);

			}

			if (mouse_y < 260 && mouse_y > 230) { // for each selection an if will work - BOX 2
				temp = 2;
				displayToolbox();

				highlightSelection(700, 260, 730, 230);

			}

			if (mouse_y < 222 && mouse_y > 192) { // for each selection an if will work - BOX 3
				temp = 3;
				displayToolbox();

				highlightSelection(700, 222, 730, 192);

			}

			if (mouse_y < 184 && mouse_y > 154) { 
				temp = 4;
				displayToolbox();

				highlightSelection(700, 184, 730, 154);

			}

			if (mouse_y < 146 && mouse_y>116) {
				temp = 5;
				displayToolbox();
				highlightSelection(700, 146, 730, 116);
			}

			if (mouse_y < 108 && mouse_y > 78) {
				temp = 6;
				displayToolbox();
				highlightSelection(700, 108, 730, 78);
			}

			if (mouse_y < 70 && mouse_y>40) {
				temp = 8;
				displayToolbox();
				highlightSelection(700, 70, 730, 40);
			}

			if (mouse_y < 298 && mouse_y>268 && mouse_x < 700) { //curve
				temp = 9;
				displayToolbox();
				highlightSelection(660, 298, 690, 268);
			}


			if (mouse_y < 260 && mouse_y>230 && mouse_x<700) {
				temp = 10;
				displayToolbox();
				highlightSelection(660, 260, 690, 230);
			}

			if (mouse_y < 222 && mouse_y>192 && mouse_x < 700) { //erase
				temp = 11;
				displayToolbox();
				highlightSelection(660, 222, 690, 192);
			}

			if (mouse_y < 184 && mouse_y>154 && mouse_x < 700) { //fill
				temp = 12;
				displayToolbox();
				highlightSelection(660, 184, 690, 154);
			}

			if (mouse_y < 146 && mouse_y>116 && mouse_x < 700) { //save
				temp = 13;
				displayToolbox();
				highlightSelection(660, 146, 690, 116);
			}

			
			if (mouse_y < 108 && mouse_y>78 && mouse_x < 700) { //load
				temp = 14;
				displayToolbox();
				highlightSelection(660, 108, 690, 78);
			}
		}
	return temp;

}


bool checkforColor(int x, int y, int & color) {
	if (x > 700 && x < 730) {
		if (y < -40 && y >-70) {
			displayPalette();
			highlightSelection(700, -40, 730, - 70);
			color = 2;
			return true;
		}
		if (y < -80 && y >-110) {
			displayPalette();
			highlightSelection(700, -78, 730, -108);
			color = 3;
			return true;
		}
		if (y < -120 && y >-150) {
			displayPalette();
			highlightSelection(700, -116, 730, -146);
			color = 4;
			return true;
		}
		if (y < -154 && y >-184) {
			displayPalette();
			highlightSelection(700, -154, 730, -184);
			color = 5;
			return true;
		}
		if (y < -192 && y >-222) {
			displayPalette();
			highlightSelection(700, -192, 730, -222);
			color = 13;
			return true;
		}
		if (y < -230 && y >-260) {
			displayPalette();
			highlightSelection(700, -230, 730, -260);
			color = 1;
			return true;
		}
		if (y < -268 && y >-298) {
			displayPalette();
			highlightSelection(700, -268, 730, -298);
			color = 0;
			return true;
		}
		return false;
	}
	return false;
}



void handle_kbd(char c)
{
	
	GP142_printfXY(WHITE, 0, 0,   TEXT_SIZE, "%c", c);
}


void demo_handle_periodic(void){};


/******************************************************************************
Drawing Functions
 ******************************************************************************/


int main(void)
{     
    int quit = 0;         
    int mouse_x, mouse_y;
    char key_pressed;
    GP142_open();          
	displayMenu();
	displayToolbox();
	displayPalette();

	struct filldetails{
		int x;
		int y;
		int color;
	};
	

	int pcount=0;
	int points[6];

	
	int previousSelection = 0;
	int selection = 0;
	int colorSelection = 0;

	//hierarchy files

	vector<shape*> main;
	int totalShapes=0;
	int textsize = 0;
	vector<point> cord;
	vector<filldetails> fillpoints;
	
    //The Event Loop  
    while (!quit) {
		
		
        switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
            case GP142_QUIT:
                quit = 1; 
                break;
   
			case GP142_MOUSE:
				
				
				
				selection = makeSelection(mouse_x, mouse_y);

				if (!checkforColor(mouse_x, mouse_y, colorSelection)) {
					
					if (selection != 0) {
						previousSelection = selection;
						pcount = 0;
					}

					

					if (selection == 0) {
						
						if (previousSelection == 1) { // test to make circle.
							
							points[2 * pcount] = mouse_x;
							points[2 * pcount + 1] = mouse_y;
							pcount++;

							if (pcount == 2)
							{
								pcount = 0;
								point* centre = new point[1];
								centre[0].x = points[0];
								centre[0].y = points[1];
								int radius = sqrt((pow(points[3] - points[1], 2)) + (pow(points[2] - points[0], 2)));
								shape* obj = new circle(centre, radius, colorSelection, 1);
								obj->draw();
								main.push_back(obj);
								totalShapes++;
							}

						}

						if (previousSelection == 2) { // test to make line.
							points[2*pcount]=mouse_x;
							points[pcount * 2 + 1] = mouse_y;
							
							pcount++;
							if (pcount == 2) {
								point* coordinates = new point[2];
								coordinates[0].x = points[0];
								coordinates[0].y = points[1];
								coordinates[1].x = points[2];
								coordinates[1].y = points[3];

								pcount = 0;
								openshape* obj = new line(1, coordinates, colorSelection, 2);
								obj->draw();
								main.push_back(obj);
								totalShapes++;
								
							}

						}

						if (previousSelection == 3) { // text
							points[2 * pcount] = mouse_x;
							points[pcount * 2 + 1] = mouse_y;

							pcount++;
							if (pcount == 1) {
								point* coordinates = new point[1];
								coordinates[0].x = points[0];
								coordinates[0].y = points[1];
								
								int i = 0;
								int space = 14;
								string textcontent;
								string words;
								while (key_pressed != '\r') {
									GP142_await_event(&mouse_x, &mouse_y, &key_pressed);
									textcontent += key_pressed;
									words = key_pressed;
									words += '\0';
									
									
									
									if (i == 0)
									GP142_printfXY(colorSelection, points[0], points[1], 20, words.c_str());
									else
										GP142_printfXY(colorSelection, points[0]+space*i, points[1], 20, words.c_str());
										
									i++;

								}
								
								textcontent[i-1] = '\0';
								
								textsize = 20;
								pcount = 0;
								shape* obj = new text(textsize,textcontent.c_str(),coordinates, colorSelection, 1);
								
								main.push_back(obj);
								totalShapes++;

							}

						}

						if (previousSelection == 4) { // rectangle
							points[2 * pcount] = mouse_x;
							points[pcount * 2 + 1] = mouse_y;

							pcount++;
							if (pcount == 2) {
								point* coordinates = new point[2];
								coordinates[0].x = points[0];
								coordinates[0].y = points[1];
								coordinates[1].x = points[2];
								coordinates[1].y = points[3];
								pcount = 0;
								polygon* obj = new rectangle(coordinates, colorSelection, 2);
								obj->draw();
								main.push_back(obj);
								totalShapes++;

							}

						}

						if (previousSelection == 5) { // triangle
							points[2 * pcount] = mouse_x;
							points[pcount * 2 + 1] = mouse_y;

							pcount++;
							if (pcount == 3) {
								point* coordinates = new point[3];
								coordinates[0].x = points[0];
								coordinates[0].y = points[1];
								coordinates[1].x = points[2];
								coordinates[1].y = points[3];
								coordinates[2].x = points[4];
								coordinates[2].y = points[5];
								pcount = 0;
								polygon* obj = new triangle(coordinates, colorSelection, 3);
								obj->draw();
								main.push_back(obj);
								totalShapes++;

							}

						}

						if (previousSelection == 6) { // polygon
							if (pcount == 0)
								cord.clear();
							point add;
							add.x= mouse_x;
							add.y = mouse_y;
							cord.push_back(add);
							pcount++;
							bool count = false;
							if (pcount > 2) 
							{
								if (mouse_x == cord[pcount - 2].x && mouse_y == cord[pcount - 2].y)
									count = true;
							}

							if (count) {
								
								point* coordinates = new point[pcount+1];
								for (int i = 0; i < pcount; i++) {
									coordinates[i].x = cord[i].x;
									coordinates[i].y = cord[i].y;
									coordinates[i + 1].x = cord[i - i].x;
									coordinates[i + 1].y = cord[i - i].y;
								}
								
								shape* obj = new polygon(coordinates, colorSelection, pcount);
								obj->draw();
								main.push_back(obj);
								pcount = 0;
								totalShapes++;
							}

						}

						

						if (previousSelection == 9) { // test to make curve.
							if (pcount == 0)
								cord.clear();
							point add;
							add.x = mouse_x;
							add.y = mouse_y;
							cord.push_back(add);
							pcount++;
							bool count = false;
							if (pcount > 2)
							{
								if (mouse_x == cord[pcount - 2].x && mouse_y == cord[pcount - 2].y)
									count = true;
							}

							if (count) {

								point* coordinates = new point[pcount];
								for (int i = 0; i < pcount; i++) {
									coordinates[i].x = cord[i].x;
									coordinates[i].y = cord[i].y;
								}

								shape* obj = new curve(1,coordinates, colorSelection, pcount);
								obj->draw();
								main.push_back(obj);
								totalShapes++;
								pcount = 0;

							}
						}


						if (previousSelection == 10) { // test to make dotted line.
							points[2 * pcount] = mouse_x;
							points[pcount * 2 + 1] = mouse_y;

							pcount++;
							if (pcount == 2) {
								point* coordinates = new point[2];
								coordinates[0].x = points[0];
								coordinates[0].y = points[1];
								coordinates[1].x = points[2];
								coordinates[1].y = points[3];

								pcount = 0;
								openshape* obj = new line(0, coordinates, colorSelection, 2);
								obj->draw();
								main.push_back(obj);
								totalShapes++;

							}

						}
						
						if (previousSelection == 12) { // fill
							filldetails p;
							point d;
							d.x = mouse_x;
							d.y = mouse_y;
							p.x = mouse_x;
							p.y = mouse_y;
							p.color = colorSelection;
							for (int i = 0; i < main.size(); i++) {
								if (main[i]->contain(d)) {
									main[i]->fill(colorSelection);
									fill(mouse_x, mouse_y, 1, colorSelection);
								}
								fillpoints.push_back(p);
							}
							
						}

						if (previousSelection == 11) { // erase
							point p;
							p.x = mouse_x;
							p.y = mouse_y;
							for (int i = 0; i < main.size(); i++) {
								if (main[i]->contain(p)) {
									delete main[i];
									for (int j = i; j < (main.size())-1; j++) {
										main[j] = main[j + 1];

									}
									main.pop_back();
									GP142_clear();
									displayMenu();
									displayToolbox();
									displayPalette();
									for (int i = 0; i < main.size(); i++) {
										main[i]->draw();
									}
									
								}

							}

						}

					}

					if (selection == 8) { // clear settings
						GP142_clear();
						displayMenu();
						displayToolbox();
						displayPalette();
						main.clear();
						cord.clear();
						totalShapes = 0;

					}

					if (selection == 13) { // save
						GP142_printfXY(BLACK, -700, 397, 10, "FILE SAVED!");
						ofstream out;

						out.open("paint.txt");
						if (out) {
							out << totalShapes << endl;
							for (int i = 0; i<int(main.size()); i++) {
								out << main[i]->save();
								out << endl;
							}
						}


					}

					if (selection == 14) { // load
						ifstream in;
						
						in.open("paint.txt");
						if (in) {
							displayMenu();
							displayToolbox();
							displayPalette();
							
							int numofshapes = 0;
							in >> numofshapes;
							string shapename;
							
							for (int i = 0; i < numofshapes; i++) {
								in >> shapename;
								
								if (shapename=="circle") {
									double rad;
									int x, y, col;
									in >> x >> y >> rad >> col;
									point* cen = new point[1];
									cen->x = x;
									cen->y = y;
									shape* obj = new circle(cen, rad, col, 1);
									obj->draw();
									main.push_back(obj);
									totalShapes++;

								}

								else if (shapename == "line") {
									int x1, x2, y1, y2, col;
									in >> x1 >> y1 >> x2 >> y2 >> col;

									point* coordinates = new point[2];
									coordinates[0].x = x1;
									coordinates[0].y = y1;
									coordinates[1].x = x2;
									coordinates[1].y = y2;

									openshape* obj = new line(1, coordinates, col, 2);
									obj->draw();
									main.push_back(obj);
									totalShapes++;
								
								}

								else if (shapename == "curve") {
									
									int x1, x2, y1, y2, col,n;
									in >> n;
									in >> col;
									point* coordinates = new point[n];
									int i = 0;
									for (i = 0; i < n-1; i++) {
										in >> x1 >> y1;
										
										coordinates[i].x = x1;
										coordinates[i].y = y1;
										

									}
									
									
									openshape* obj = new curve(1, coordinates, col, n);
									obj->draw();
									main.push_back(obj);
									totalShapes++;
									
									cord.clear();

								}
								else if (shapename == "polygon") {
									
									int count = 0;

									int x, y,col,num;
									in >> num;
									in >> col;
									point temp;
									
									for (int i = 0; i < num;i++) {
										in >> x >> y;
										temp.x = x;
										temp.y = y;
										cord.push_back(temp);
										count++;
									}
									

									point* coordinates = new point[count+1];
									for (int i = 0; i < count; i++) {
										coordinates[i].x = cord[i].x;
										coordinates[i].y = cord[i].y;	
									}
									coordinates[count].x = cord[0].x;
									coordinates[count].y = cord[0].y;

									
									shape* obj = new polygon(coordinates, col, count);
									obj->draw();
									main.push_back(obj);
									totalShapes++;
									cord.clear();
								}


								else if (shapename == "rectangle") {
									
									int x1, y1,x2,y2, col;
									in >> x1 >> y1 >> x2 >> y2 >> col;
									
									point* p = new point[2];
									p[0].x = x1;
									p[0].y = y1;
									p[1].x = x2;
									p[1].y = y2;

									
									polygon* obj = new rectangle(p, col, 1);
									obj->draw();
									main.push_back(obj);
									totalShapes++;

								}

								else if (shapename == "triangle") {
									
									int x1, y1, x2, y2,x3,y3, col;
									in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> col;
									point* p = new point[3];
									p[0].x = x1;
									p[0].y = y1;
									p[1].x = x2;
									p[1].y = y2;
									p[2].x = x3;
									p[2].y = y3;
									polygon* obj = new triangle(p, col, 1);
									obj->draw();
									main.push_back(obj);
									totalShapes++;

								}

								else if (shapename == "text") {
									char words[125];
									int x, y,col;
									in >> col;
									in >> x >> y;
									
									in.getline(words, 125);

									point* coordinates = new point[1];
									coordinates[0].x = x;
									coordinates[0].y = y;

									
									shape* obj = new text(textsize, words, coordinates, colorSelection, 1);
									GP142_textXY(col, x, y, 20, words);
									main.push_back(obj);
									totalShapes++;

								}

							
							}
							
							for (int i = 0; i < fillpoints.size(); i++) {
								fill(fillpoints[i].x, fillpoints[i].y, 1, fillpoints[i].color);
							
							}


						}
						
						
					}
					
					border();
				}
				
				
				
                break;
               
            case GP142_KBD:
				//Keyboard handler
                handle_kbd(key_pressed);

				
                break;
 
            default:
                break;
        }
    }
        
    GP142_close();          /* Clean up and close graphics window           */
    
    return 0;
}









