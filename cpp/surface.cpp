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
    
    //fill the coordinates with interpolation
    interpolate();
};

Point Surface::getPoint(int i, int j){
    return coordinates[i + Nx*j];
};

void Surface::interpolate(){

    cout << "Surface::interpolate called" << endl;
    cout << "Nx: " << Nx << ", Ny: " << Ny << endl;

};

void Surface::showCoordinates(){};
void Surface::printCoordinatesToFile(string filename){};
void Surface::setPoint(int i, int j, Point p_in){};
