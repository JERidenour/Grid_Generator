#include "point.h"
#include "line.h"
#include "surface.h"
#include <iostream>

using namespace std;

int main(){

    int Nx = 15;
    int Ny = 5;
    double hx = 0.5;
    double hy = 1.0;

    Point p;
    Line North = Line(Nx); 
    Line South = Line(Nx); 
    Line East = Line(Ny); 
    Line West = Line(Ny); 

    for(int i = 0; i < Nx; i++){

        p.setPoint( (double)i*hx, 4, 0);
        North.setPoint(i, p);

        p.setPoint( (double)i*hx, 0, 0);
        South.setPoint(i, p);
    }
    for(int j = 0; j < Ny; j++){

        p.setPoint( 7, (double)j*hy, 0);
        East.setPoint(j, p);

        p.setPoint(0, (double)j*hy, 0);
        West.setPoint(j, p);
    }

//    cout << "North:" << endl;
//    North.showCoordinates();

//    cout << "South:" << endl;
//    South.showCoordinates();

//    cout << "East:" << endl;
//    East.showCoordinates();

//    cout << "West:" << endl;
//    West.showCoordinates();


    Surface testSurf = Surface(North, South, East, West);
    testSurf.showCoordinates();

    return 0;
}
