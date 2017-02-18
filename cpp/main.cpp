#include "point.h"
#include "line.h"
#include "surface.h"
#include "grid.h"
#include <iostream>

using namespace std;

int main(){

    cout << "setting constants..." << endl;

    //set numerical constants
    //number of points in each direction
    int Nx = 15;
    int Ny = 15;
    int Nz = 15;

    //"zConst" for flat edges
    double z1 = 0.0;
    double z2 = 1.0;
    double z3 = 1.0;
    double z4 = 0.0;
    double z5 = 0.0;
    double z6 = 1.0;

    //step sizes
    double hx = 1/( (double)Nx - 1 );
    double hy = 1/( (double)Ny - 1 );
    double hz = 1/( (double)Nz - 1 );

    cout << "creating boundary lines..." << endl;

    //initialize datatypes
    Point p;
    Line line_1 = Line(Nx); 
    Line line_2 = Line(Ny); 
    Line line_3 = Line(Nx); 
    Line line_4 = Line(Ny); 
    Line line_5 = Line(Nz); 
    Line line_6 = Line(Nz); 
    Line line_7 = Line(Nz); 
    Line line_8 = Line(Nz); 
    Line line_9 = Line(Nx); 
    Line line_10 = Line(Ny); 
    Line line_11 = Line(Nx); 
    Line line_12 = Line(Ny); 

    //fill the lines with points
    for(int i = 0; i < Nx; i++){

        p.setPoint( (double)i*hx, 0, 0);
        line_1.setPoint(i, p);

        p.setPoint( (double)i*hx, 1, 0);
        line_3.setPoint(i, p);

        p.setPoint( (double)i*hx, 0, 1);
        line_9.setPoint(i, p);

        p.setPoint( (double)i*hx, 1, 1);
        line_11.setPoint(i, p);
    }
    for(int j = 0; j < Ny; j++){

        p.setPoint( 1, (double)j*hy, 0);
        line_2.setPoint(j, p);

        p.setPoint(0, (double)j*hy, 0);
        line_4.setPoint(j, p);

        p.setPoint( 1, (double)j*hy, 1);
        line_10.setPoint(j, p);

        p.setPoint(0, (double)j*hy, 1);
        line_12.setPoint(j, p);
    }
    for(int k = 0; k < Nz; k++){

        p.setPoint( 0, 0 , (double)k*hz);
        line_5.setPoint(k, p);

        p.setPoint( 1, 0 , (double)k*hz);
        line_6.setPoint(k, p);

        p.setPoint( 1, 1 , (double)k*hz);
        line_7.setPoint(k, p);

        p.setPoint( 0, 1 , (double)k*hz);
        line_8.setPoint(k, p);

    }

    cout << "creating surfaces..." << endl;

    //initialize surface
    int norm_1 = 1;
    int norm_2 = 0;
    int norm_3 = 1;
    int norm_4 = 0;
    int norm_5 = 2;
    int norm_6 = 2;

    //Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, 
    //        int &norm, double &zConst)
    Surface surf_1 = Surface(line_9, line_1, line_6, line_5, norm_1, z1);
    Surface surf_2 = Surface(line_10, line_2, line_6, line_7, norm_2, z2);
    Surface surf_3 = Surface(line_11, line_3, line_7, line_8, norm_3, z3);
    Surface surf_4 = Surface(line_12, line_4, line_5, line_8, norm_4, z4);
    Surface surf_5 = Surface(line_1, line_3, line_2, line_4, norm_5, z5);
    Surface surf_6 = Surface(line_9, line_11, line_10, line_12, norm_6, z6);

    cout << "writing surfaces to file..." << endl;

    //write the points to file
    surf_1.printCoordinatesToFile("../viz/surf_1.txt");
    surf_2.printCoordinatesToFile("../viz/surf_2.txt");
    surf_3.printCoordinatesToFile("../viz/surf_3.txt");
    surf_4.printCoordinatesToFile("../viz/surf_4.txt");
    surf_5.printCoordinatesToFile("../viz/surf_5.txt");
    surf_6.printCoordinatesToFile("../viz/surf_6.txt");

    cout << "creating 3D grid..." << endl;

    //create 3D-grid with interior points
    //grid(boundNordh, boundSouth, boundEast, boundWest, boundFront, boundBack)
    Grid grid_1 = Grid(surf_6, surf_5, surf_2, surf_4, surf_1, surf_3);

    grid_1.printCoordinatesToFile("../viz/grid_1.txt");

    cout << "done with first method!" << endl;
    cout << "attempting second method..." << endl;

    Nx = 51;
    Ny = 50;
    Surface surf_top = Surface("../topodata/OROdat.txt", Nx, Ny); 
    surf_top.printCoordinatesToFile("../viz/surf_top.txt");
    cout << "done!" << endl;


    return 0;
}
