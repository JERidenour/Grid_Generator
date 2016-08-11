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
    interpolate(boundNorth, boundSouth, boundEast, boundWest);
};

Point Surface::getPoint(int i, int j){
    return coordinates[i + Nx*j];
};

void Surface::interpolate(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest){

    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){

            xi = i/( (double) Nx-1);
            eta = j/( (double) Ny-1);

            double x, y, z;
            
            x = (1-xi)*boundWest.getPoint(j).getX() + xi*boundEast.getPoint(j).getX() 
                + (1-eta)*boundSouth.getPoint(i).getX() + eta*boundNorth.getPoint(i).getX()
                - (1-xi)*(1-eta)*boundSouth.getPoint(0).getX()
                - xi*(1-eta)*boundSouth.getPoint(Nx-1).getX()
                - eta*(1-xi)*boundNorth.getPoint(0).getX()
                - eta*xi*boundNorth.getPoint(Nx-1).getX();

            y = (1-xi)*boundWest.getPoint(j).getY() + xi*boundEast.getPoint(j).getY() 
                + (1-eta)*boundSouth.getPoint(i).getY() + eta*boundNorth.getPoint(i).getY()
                - (1-xi)*(1-eta)*boundSouth.getPoint(0).getY()
                - xi*(1-eta)*boundSouth.getPoint(Nx-1).getY()
                - eta*(1-xi)*boundNorth.getPoint(0).getY()
                - eta*xi*boundNorth.getPoint(Nx-1).getY();

            z = 0;

            Point p = Point(x, y, z);
            setPoint(i, j, p);

        }
    }
};

void Surface::showCoordinates(){

    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            coordinates[i+j*Nx].showPoint();
        }
    }

};
void Surface::printCoordinatesToFile(string filename){};
void Surface::setPoint(int i, int j, Point p_in){

    coordinates[i+j*Nx] = p_in;

};
