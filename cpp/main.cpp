#include "point.h"
#include "line.h"
#include "surface.h"
#include <iostream>

using namespace std;

int main(){

    //set numerical constants
    int Nx = 15;
    int Ny = 15;
    double hx = 0.5;
    double hy = 0.5;

    //initialize datatypes
    Point p;
    Line line_1 = Line(Nx); 
    Line line_2 = Line(Ny); 
    Line line_3 = Line(Nx); 
    Line line_4 = Line(Ny); 

    //fill the lines with points
    for(int i = 0; i < Nx; i++){

        p.setPoint( (double)i*hx, 4, 0);
        line_1.setPoint(i, p);

        p.setPoint( (double)i*hx, 0, 0);
        line_3.setPoint(i, p);
    }
    for(int j = 0; j < Ny; j++){

        p.setPoint( 7, (double)j*hy, 0);
        line_2.setPoint(j, p);

        p.setPoint(0, (double)j*hy, 0);
        line_4.setPoint(j, p);
    }


    //initialize surface
    int norm_1 = 0;
    int norm_2 = 1;
    int norm_3 = 2;

    Surface surf_1 = Surface(line_3, line_1, line_2, line_4, norm_1);
    Surface surf_2 = Surface(line_3, line_1, line_2, line_4, norm_2);
    Surface surf_3 = Surface(line_3, line_1, line_2, line_4, norm_3);

    //write the points to file
    surf_1.printCoordinatesToFile("../viz/surf_1.txt");
    surf_2.printCoordinatesToFile("../viz/surf_2.txt");
    surf_3.printCoordinatesToFile("../viz/surf_3.txt");

    return 0;
}
