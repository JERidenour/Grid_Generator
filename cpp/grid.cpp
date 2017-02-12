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

    //allocate memory for help arrays:
    double * U_X;
    U_X = new double[Nx*Ny*Nz];
    double * V_X;
    V_X  = new double[Nx*Ny*Nz];
    double * W_X;
    W_X  = new double[Nx*Ny*Nz];
    double * UW_X;
    UW_X  = new double[Nx*Ny*Nz];
    double * UV_X;
    UV_X  = new double[Nx*Ny*Nz];
    double * VW_X;
    VW_X  = new double[Nx*Ny*Nz];
    double * UVW_X;
    UVW_X  = new double[Nx*Ny*Nz];

    double * U_Y;
    U_Y = new double[Nx*Ny*Nz];
    double * V_Y;
    V_Y  = new double[Nx*Ny*Nz];
    double * W_Y;
    W_Y  = new double[Nx*Ny*Nz];
    double * UW_Y;
    UW_Y  = new double[Nx*Ny*Nz];
    double * UV_Y;
    UV_Y  = new double[Nx*Ny*Nz];
    double * VW_Y;
    VW_Y  = new double[Nx*Ny*Nz];
    double * UVW_Y;
    UVW_Y  = new double[Nx*Ny*Nz];

    double * U_Z;
    U_Z = new double[Nx*Ny*Nz];
    double * V_Z;
    V_Z  = new double[Nx*Ny*Nz];
    double * W_Z;
    W_Z  = new double[Nx*Ny*Nz];
    double * UW_Z;
    UW_Z  = new double[Nx*Ny*Nz];
    double * UV_Z;
    UV_Z  = new double[Nx*Ny*Nz];
    double * VW_Z;
    VW_Z  = new double[Nx*Ny*Nz];
    double * UVW_Z;
    UVW_Z  = new double[Nx*Ny*Nz];


    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            for(int k=0; k<Nz; k++){
   
                xi = i/( (double) Nx-1);
                eta = j/( (double) Ny-1);
                zeta = k/( (double) Nz-1);

                double x, y, z;

                U_X[i+j*Nx+k*Nx*Ny] = (1-xi)*boundWest.getPoint(j,k).getX() + 
                                      xi*boundEast.getPoint(j,k).getX();
                V_X[i+j*Nx+k*Nx*Ny] = (1-eta)*boundFront.getPoint(i,k).getX() +
                                       eta*boundBack.getPoint(i,k).getX();
                W_X[i+j*Nx+k*Nx*Ny] = (1-zeta)*boundSouth.getPoint(i,j).getX() +
                                       zeta*boundNorth.getPoint(i,j).getX();

                //UW_X(i,j,k) = (1-xi)*(1-zeta)*x_4(j) + zeta*(1-xi)*x_12(j) + 
                //            xi*(1-zeta)*x_2(j) + xi*zeta*x_10(j);
                
            }
        }
    } 
    //release help array memory
    delete[] U_X; 
    delete[] V_X; 
    delete[] W_X; 
    delete[] UW_X;
    delete[] UV_X;
    delete[] VW_X;
    delete[] UVW_X;
    delete[] U_Y; 
    delete[] V_Y; 
    delete[] W_Y; 
    delete[] UW_Y;
    delete[] UV_Y;
    delete[] VW_Y;
    delete[] UVW_Y;
    delete[] U_Z; 
    delete[] V_Z; 
    delete[] W_Z; 
    delete[] UW_Z;
    delete[] UV_Z;
    delete[] VW_Z;
    delete[] UVW_Z;

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

                outFile << coordinates[i + j*Nx + k*Nx*Ny].pointAsString() << "\n";

            }
        }
    }
    outFile.close();
};

void Grid::setPoint(int i, int j, int k, Point p_in){

    coordinates[i + j*Nx + k*Nx*Ny] = p_in;

};
