#include "domain.h"
#include "line.h"
#include "surface.h"
#include <iostream>
#include <fstream>

using namespace std;

Surface::Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm, double &zConst){

    Nx = boundSouth.getN();
    Ny = boundWest.getN();
    Nz = 0;

    //allocate coordinates array of Nx*Ny elements
    coordinates = new Point[Nx*Ny];
    
    //fill the coordinates with interpolation
    interpolate(boundNorth, boundSouth, boundEast, boundWest, norm, zConst);
};

Point Surface::getPoint(int i, int j){
    return coordinates[i + Nx*j];
};

int Surface::getNx(){return Nx;};
int Surface::getNy(){return Ny;};

void Surface::interpolate(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm, double &zConst){

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

            z = zConst;

            Point p = Point();
            if (norm == 0) {
                p.setPoint(z, y, x);
            }
            if (norm == 1) {
                p.setPoint(x, z, y);
            }
            if (norm == 2) {
                p.setPoint(x, y, z);
            }
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
void Surface::printCoordinatesToFile(string filename){

    ofstream outFile;
    outFile.open(filename);
    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            outFile << coordinates[i+j*Nx].pointAsString() << "\n";
        }
    }

    outFile.close();

};
void Surface::setPoint(int i, int j, Point p_in){

    coordinates[i+j*Nx] = p_in;

};
