#include "domain.h"
#include "surface.h"
#include "grid.h"
#include <iostream>
#include <fstream>

using namespace std;

Grid::Grid(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, 
        Surface &boundWest, Surface &boundFront, Surface &boundBack){

    Nx = boundSouth.getNx();
    Ny = boundSouth.getNy();
    Nz = boundFront.getNy();    

    coordinates = new Point[Nx*Ny*Nz];
    
    interpolate(boundNorth, boundSouth, boundEast, boundWest, boundFront, boundBack);
};

Grid::Grid(Surface &boundNorth, int Nz_in, double depth_in){

    Nx = boundNorth.getNx();
    Ny = boundNorth.getNy();
    Nz = Nz_in;

    coordinates = new Point[Nx*Ny*Nz];

    Surface boundSouth = createSouth(boundNorth);       

//    interpolate(boundNorth, boundSouth, boundEast, boundWest, boundFront, boundBack);
};

Point Grid::getPoint(int i, int j, int k){
    return coordinates[i + Nx*j + k*Nx*Ny];
};

void Grid::interpolate(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, 
        Surface &boundWest, Surface &boundFront, Surface &boundBack){

    //allocate memory for help arrays:
    double * U_X;
    double * V_X;
    double * W_X;
    double * UW_X;
    double * UV_X;
    double * VW_X;
    double * UVW_X;
    double * U_Y;
    double * V_Y;
    double * W_Y;
    double * UW_Y;
    double * UV_Y;
    double * VW_Y;
    double * UVW_Y;
    double * U_Z;
    double * V_Z;
    double * W_Z;
    double * UW_Z;
    double * UV_Z;
    double * VW_Z;
    double * UVW_Z;


    U_X = new double[Nx*Ny*Nz];
    V_X  = new double[Nx*Ny*Nz];
    W_X  = new double[Nx*Ny*Nz];
    UW_X  = new double[Nx*Ny*Nz];
    UV_X  = new double[Nx*Ny*Nz];
    VW_X  = new double[Nx*Ny*Nz];
    UVW_X  = new double[Nx*Ny*Nz];
    U_Y = new double[Nx*Ny*Nz];   
    V_Y  = new double[Nx*Ny*Nz];
    W_Y  = new double[Nx*Ny*Nz];
    UW_Y  = new double[Nx*Ny*Nz];
    UV_Y  = new double[Nx*Ny*Nz];
    VW_Y  = new double[Nx*Ny*Nz];
    UVW_Y  = new double[Nx*Ny*Nz];
    U_Z = new double[Nx*Ny*Nz];
    V_Z  = new double[Nx*Ny*Nz];   
    W_Z  = new double[Nx*Ny*Nz];   
    UW_Z  = new double[Nx*Ny*Nz];
    UV_Z  = new double[Nx*Ny*Nz];
    VW_Z  = new double[Nx*Ny*Nz];
    UVW_Z  = new double[Nx*Ny*Nz];

    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            for(int k=0; k<Nz; k++){
   
                xi = i/( (double) Nx-1);
                eta = j/( (double) Ny-1);
                zeta = k/( (double) Nz-1);



                U_X[i+j*Nx+k*Nx*Ny] = (1-xi)*boundWest.getPoint(j,k).getX() + 
                                      xi*boundEast.getPoint(j,k).getX();
                V_X[i+j*Nx+k*Nx*Ny] = (1-eta)*boundFront.getPoint(i,k).getX() +
                                       eta*boundBack.getPoint(i,k).getX();
                W_X[i+j*Nx+k*Nx*Ny] = (1-zeta)*boundSouth.getPoint(i,j).getX() +
                                       zeta*boundNorth.getPoint(i,j).getX();

                UW_X[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-zeta)*boundWest.getSouth()->getPoint(j).getX() + 
                                       zeta*(1-xi)*boundWest.getNorth()->getPoint(j).getX() + 
                                       xi*(1-zeta)*boundEast.getSouth()->getPoint(j).getX() + 
                                       xi*zeta*boundEast.getNorth()->getPoint(j).getX();

                UV_X[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*boundWest.getEast()->getPoint(k).getX() + 
                                       eta*(1-xi)*boundWest.getWest()->getPoint(k).getX() + 
                                       xi*(1-eta)*boundEast.getEast()->getPoint(k).getX() + 
                                       xi*eta*boundEast.getWest()->getPoint(k).getX();

                VW_X[i+j*Nx+k*Nx*Ny] = (1-zeta)*(1-eta)*boundFront.getSouth()->getPoint(i).getX() + 
                                       zeta*(1-eta)*boundFront.getNorth()->getPoint(i).getX() + 
                                       eta*(1-zeta)*boundBack.getSouth()->getPoint(i).getX() + 
                                       zeta*eta*boundBack.getNorth()->getPoint(i).getX();
               
                UVW_X[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*(1-zeta)*boundFront.getSouthWestCorner().getX() + 
                                       (1-xi)*(1-eta)*zeta*boundFront.getNorthWestCorner().getX() + 
                                       (1-xi)*eta*(1-zeta)*boundBack.getSouthWestCorner().getX() + 
                                       xi*(1-eta)*(1-zeta)*boundFront.getSouthEastCorner().getX() +
                                       (1-xi)*eta*zeta*boundBack.getNorthWestCorner().getX() +
                                       xi*(1-eta)*zeta*boundFront.getNorthEastCorner().getX()  +
                                       (1-zeta)*xi*eta*boundBack.getSouthEastCorner().getX() + 
                                       xi*eta*zeta*boundBack.getNorthEastCorner().getX();

 
                U_Y[i+j*Nx+k*Nx*Ny] = (1-xi)*boundWest.getPoint(j,k).getY() + 
                                      xi*boundEast.getPoint(j,k).getY();
                V_Y[i+j*Nx+k*Nx*Ny] = (1-eta)*boundFront.getPoint(i,k).getY() +
                                       eta*boundBack.getPoint(i,k).getY();
                W_Y[i+j*Nx+k*Nx*Ny] = (1-zeta)*boundSouth.getPoint(i,j).getY() +
                                       zeta*boundNorth.getPoint(i,j).getY();

                UW_Y[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-zeta)*boundWest.getSouth()->getPoint(j).getY() + 
                                       zeta*(1-xi)*boundWest.getNorth()->getPoint(j).getY() + 
                                       xi*(1-zeta)*boundEast.getSouth()->getPoint(j).getY() + 
                                       xi*zeta*boundEast.getNorth()->getPoint(j).getY();

                UV_Y[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*boundWest.getEast()->getPoint(k).getY() + 
                                       eta*(1-xi)*boundWest.getWest()->getPoint(k).getY() + 
                                       xi*(1-eta)*boundEast.getEast()->getPoint(k).getY() + 
                                       xi*eta*boundEast.getWest()->getPoint(k).getY();

                VW_Y[i+j*Nx+k*Nx*Ny] = (1-zeta)*(1-eta)*boundFront.getSouth()->getPoint(i).getY() + 
                                       zeta*(1-eta)*boundFront.getNorth()->getPoint(i).getY() + 
                                       eta*(1-zeta)*boundBack.getSouth()->getPoint(i).getY() + 
                                       zeta*eta*boundBack.getNorth()->getPoint(i).getY();
               
                UVW_Y[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*(1-zeta)*boundFront.getSouthWestCorner().getY() + 
                                       (1-xi)*(1-eta)*zeta*boundFront.getNorthWestCorner().getY() + 
                                       (1-xi)*eta*(1-zeta)*boundBack.getSouthWestCorner().getY() + 
                                       xi*(1-eta)*(1-zeta)*boundFront.getSouthEastCorner().getY() +
                                       (1-xi)*eta*zeta*boundBack.getNorthWestCorner().getY() +
                                       xi*(1-eta)*zeta*boundFront.getNorthEastCorner().getY()  +
                                       (1-zeta)*xi*eta*boundBack.getSouthEastCorner().getY() + 
                                       xi*eta*zeta*boundBack.getNorthEastCorner().getY();


                U_Z[i+j*Nx+k*Nx*Ny] = (1-xi)*boundWest.getPoint(j,k).getZ() + 
                                      xi*boundEast.getPoint(j,k).getZ();
                V_Z[i+j*Nx+k*Nx*Ny] = (1-eta)*boundFront.getPoint(i,k).getZ() +
                                       eta*boundBack.getPoint(i,k).getZ();
                W_Z[i+j*Nx+k*Nx*Ny] = (1-zeta)*boundSouth.getPoint(i,j).getZ() +
                                       zeta*boundNorth.getPoint(i,j).getZ();

                UW_Z[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-zeta)*boundWest.getSouth()->getPoint(j).getZ() + 
                                       zeta*(1-xi)*boundWest.getNorth()->getPoint(j).getZ() + 
                                       xi*(1-zeta)*boundEast.getSouth()->getPoint(j).getZ() + 
                                       xi*zeta*boundEast.getNorth()->getPoint(j).getZ();

                UV_Z[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*boundWest.getEast()->getPoint(k).getZ() + 
                                       eta*(1-xi)*boundWest.getWest()->getPoint(k).getZ() + 
                                       xi*(1-eta)*boundEast.getEast()->getPoint(k).getZ() + 
                                       xi*eta*boundEast.getWest()->getPoint(k).getZ();

                VW_Z[i+j*Nx+k*Nx*Ny] = (1-zeta)*(1-eta)*boundFront.getSouth()->getPoint(i).getZ() + 
                                       zeta*(1-eta)*boundFront.getNorth()->getPoint(i).getZ() + 
                                       eta*(1-zeta)*boundBack.getSouth()->getPoint(i).getZ() + 
                                       zeta*eta*boundBack.getNorth()->getPoint(i).getZ();
               
                UVW_Z[i+j*Nx+k*Nx*Ny] = (1-xi)*(1-eta)*(1-zeta)*boundFront.getSouthWestCorner().getZ() + 
                                       (1-xi)*(1-eta)*zeta*boundFront.getNorthWestCorner().getZ() + 
                                       (1-xi)*eta*(1-zeta)*boundBack.getSouthWestCorner().getZ() + 
                                       xi*(1-eta)*(1-zeta)*boundFront.getSouthEastCorner().getZ() +
                                       (1-xi)*eta*zeta*boundBack.getNorthWestCorner().getZ() +
                                       xi*(1-eta)*zeta*boundFront.getNorthEastCorner().getZ()  +
                                       (1-zeta)*xi*eta*boundBack.getSouthEastCorner().getZ() + 
                                       xi*eta*zeta*boundBack.getNorthEastCorner().getZ();

            }
        }
    } 

    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            for(int k=0; k<Nz; k++){

                double x, y, z;

                x = U_X[i+j*Nx+k*Nx*Ny]  + V_X[i+j*Nx+k*Nx*Ny]  + W_X[i+j*Nx+k*Nx*Ny]  -
                        UW_X[i+j*Nx+k*Nx*Ny]  - UV_X[i+j*Nx+k*Nx*Ny]  - VW_X[i+j*Nx+k*Nx*Ny]  +
                        UVW_X[i+j*Nx+k*Nx*Ny] ;

                y = U_Y[i+j*Nx+k*Nx*Ny]  + V_Y[i+j*Nx+k*Nx*Ny]  + W_Y[i+j*Nx+k*Nx*Ny]  -
                        UW_Y[i+j*Nx+k*Nx*Ny]  - UV_Y[i+j*Nx+k*Nx*Ny]  - VW_Y[i+j*Nx+k*Nx*Ny]  +
                        UVW_Y[i+j*Nx+k*Nx*Ny] ;

                z = U_Z[i+j*Nx+k*Nx*Ny]  + V_Z[i+j*Nx+k*Nx*Ny]  + W_Z[i+j*Nx+k*Nx*Ny]  -
                        UW_Z[i+j*Nx+k*Nx*Ny]  - UV_Z[i+j*Nx+k*Nx*Ny]  - VW_Z[i+j*Nx+k*Nx*Ny]  +
                        UVW_Z[i+j*Nx+k*Nx*Ny] ;


                Point p = Point();
                p.setPoint(x,y,z);
                setPoint(i, j, k, p);

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

Surface Grid::createSouth(Surface &boundNorth){

    int norm = 2; //norm is 2 for (x,y)-plane
    double zConst = 0.0;

    Point p =  boundNorth.getPoint(0,0);

//    Point q = boundNorth.getNorth()->getPoint(0);
//    q.showPoint();
    //get lines north, south, east, west
//    Line bNorth = Line(Nx); 
  

  
//    for(int i=0; i<Nx; i++){

//        Point p = boundNorth.getNorth()->getPoint(i);
//        p.setZ(zConst);
//        bNorth.setPoint(i,p);

//    }    

//    bNorth.showCoordinates();

//return Surface

    return Surface();

};
