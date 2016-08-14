#include "domain.h"
#include "surface.h"
#include "grid.h"
#include <iostream>
#include <fstream>

using namespace std;

Grid::Grid(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, Surface &boundWest, Surface &boundFront, Surface &boundBack){

    Nx = boundSouth.getNx();
    Ny = boundSouth.getNy();
    Nz = boundFront.getNy();    

    coordinates = new Point[Nx*Ny*Nz];
    
    interpolate(boundNorth, boundSouth, boundEast, boundWest, boundFront, boundBack);
};

Point Grid::getPoint(int i, int j, int k){
    return coordinates[i + Nx*j + k*Nx*Ny];
};

void Grid::interpolate(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, Surface &boundWest, Surface &boundFront, Surface &boundBack){
    cout << "grid interpolation invoked" << endl;
};

void Grid::showCoordinates(){

    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            for(int k=0; k<Nz; k++){

                coordinates[i + j*Nx + k*Nx*Ny].showPoint();

            }
        }
    }
};

void Grid::printCoordinatesToFile(string filename){

    ofstream outFile;
    outFile.open(filename);
    
    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            for(int k=0; k<Nz; k++){

                outFile << coordinates[i + j*Nx + k*Nx*Ny].pointAsString() << "\t";

            }
        }
    }
    outFile.close();
};

void Grid::setPoint(int i, int j, int k, Point p_in){

    coordinates[i + j*Nx + k*Nx*Ny] = p_in;

};
