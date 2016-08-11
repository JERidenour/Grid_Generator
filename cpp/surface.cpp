#include "domain.h"
#include "line.h"
#include "surface.h"
#include <iostream>
#include <fstream>

using namespace std;

Surface::Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest){

    Nx = boundSouth.getN();
    Ny = boundWest.getN();
    Nz = 0;

    //allocate coordinates array of Nx*Ny elements
    coordinates = new Point[Nx*Ny];
 
    //allocate corners array of 4 elements
    //(Surface objects always have 4 and only 4 corners)
    corners = new Point[4];
    setCorners();
    
    //fill the coordinates with interpolation
    interpolate();
};

Point Surface::getPoint(int i, int j){
    Point p = Point(0.0, 0.0, 0.0);
    return p;
};

void Surface::interpolate(){

    cout << "Surface::interpolate called" << endl;
    cout << "Nx: " << Nx << ", Ny: " << Ny << endl;

};

void Surface::showCoordinates(){};
void Surface::printCoordinatesToFile(string filename){};
void Surface::setCorners(){};
void Surface::setPoint(int i, int j, Point p_in){};
