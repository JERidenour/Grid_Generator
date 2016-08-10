#include "domain.h"
#include "line.h"
#include <iostream>
#include <fstream>

using namespace std;

Line::Line(int N_in){

    Nx = N_in;
    Ny = 0;
    Nz = 0;

    //allocate coordinates array of Nx elements
    coordinates = new Point[N_in];

    //allocate corners array of 2 elements
    //(Line objects always have 2 and only 2 corners)
    corners = new Point[2]; 

};

Point Line::getPoint(int i){return coordinates[i];};

void Line::setPoint(int i, Point p_in){coordinates[i]=p_in;};

void Line::showCoordinates(){

    for(int i=0; i<Nx; i++){

        coordinates[i].showPoint();

    }
};

void Line::printCoordinatesToFile(string filename){

    ofstream outFile;
    outFile.open(filename);
    for(int i=0; i<Nx; i++){

        outFile << coordinates[i].pointAsString() << "\t";

    }

    outFile.close();
    

};

void Line::setCorners(){

    corners[0] = coordinates[0];
    corners[1] = coordinates[Nx-1];

};
