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

    myNorth = new Line(boundNorth);
    mySouth = new Line(boundSouth);
    myEast = new Line(boundEast);
    myWest = new Line(boundWest);

    //allocate coordinates array of Nx*Ny elements
    coordinates = new Point[Nx*Ny];

    //project surface to the (x,y)-plane
    Line bNorth = boundNorth.project(norm);    
    Line bSouth = boundSouth.project(norm);    
    Line bEast = boundEast.project(norm);    
    Line bWest = boundWest.project(norm);    

    //fill the coordinates with interpolation
    interpolate(bNorth, bSouth, bEast, bWest, norm, zConst);
};

Surface::Surface(string filename, int Nx_in, int Ny_in){

    Nx = Nx_in;
    Ny = Ny_in;

    //allocate coordinates array of Nx*Ny elements
    coordinates = new Point[Nx*Ny];

    //fill coordinates from contents of file
    string line, xs, ys, zs;
    double x, y, z;
    string delim = "\t";
    ifstream myfile(filename);
    if (myfile.is_open()) {

        //while ( getline (myfile,line) ) {
        for(int i=0; i<Nx; i++){
            for(int j=0; j<Ny; j++){

                getline(myfile, line);
                size_t pos = 0;

                pos = line.find(delim);
                xs = line.substr(0, pos);
                line.erase(0, pos + delim.length());
                pos = line.find(delim);
                ys = line.substr(0, pos);
                line.erase(0, pos + delim.length());
                pos = line.find(delim);
                zs = line.substr(0, pos);

                x = stod(xs);
                y = stod(ys);
                z = stod(zs);
                Point p = Point(x,y,z);
                setPoint(i,j,p);
            }
        }
        myfile.close();
    }

  else cout << "Unable to open file"; 

    //create the data members myNorth, etc
    myNorth = new Line(Nx);
    mySouth = new Line(Nx);
    myEast = new Line(Ny);
    myWest = new Line(Ny);

    Point p1, p2;

    for(int i=0; i<Nx; i++){

        p1 = getPoint(i,(Ny-1)); //this is the line which runs across the top
        p2 = getPoint(i, 0);    // this is the line that runs across the bottom
        p1.setZ(0);
        p2.setZ(0);
        
        myNorth->setPoint(i, p1);
        mySouth->setPoint(i, p2);
    }
    
    for(int j=0; j<Ny; j++){

        p1 = getPoint((Nx-1), j); //this is the line which runs across the right 
        p2 = getPoint(0, j);    // this is the line that runs across the left 
        p1.setZ(0);
        p2.setZ(0);
        
        myEast->setPoint(j, p1);
        myWest->setPoint(j, p2);
    }

};

Point Surface::getPoint(int i, int j){
    return coordinates[i + Nx*j];
};

int Surface::getNx(){return Nx;};
int Surface::getNy(){return Ny;};

Line * Surface::getNorth(){return myNorth;};
Line * Surface::getSouth(){return mySouth;};
Line * Surface::getEast(){return myEast;};
Line * Surface::getWest(){return myWest;};

Point Surface::getNorthWestCorner(){ 
    return coordinates[ Nx*Ny - Nx ]; 
};
Point Surface::getNorthEastCorner(){ 
    return coordinates[ Nx*Ny-1 ]; 
};
Point Surface::getSouthWestCorner(){ 
    return coordinates[0]; 
};
Point Surface::getSouthEastCorner(){ 
    return coordinates[Nx-1]; 
};



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
