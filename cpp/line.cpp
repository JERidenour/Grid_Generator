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

Line::Line(const Line& Line_in){

    Nx = Line_in.Nx;
    Ny = Line_in.Ny;
    Nz = Line_in.Nz;

    coordinates = new Point[Nx];
    for(int i = 0; i < Nx; i++){
        coordinates[i] = Line_in.coordinates[i];
    }
    corners = new Point[2];
    for(int i = 0; i < 2; i++){
        corners[i] = Line_in.corners[i];
    }
};

Point Line::getPoint(int i){

    if( (i<Nx)&&(i>=0) ){
        return coordinates[i];
    }else{
        cout << "invalid index at getPoint()" << endl;
        Point errP = Point(-9999, -9999, -9999);
        return errP;
    }
};

void Line::setPoint(int i, Point p_in){

    if( (i<Nx)&&(i>=0) ){
        coordinates[i]=p_in;
    }else{
        cout << "invalid index at setPoint()" << endl;
    }
};

int Line::getN(){return Nx;};

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
