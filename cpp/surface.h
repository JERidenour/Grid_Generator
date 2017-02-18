#ifndef SURFACE
#define SURFACE

#include "line.h"
#include "point.h"
#include <string>

class Surface : public Domain {

    public:
        //default constructor
        Surface() : Domain(){};

        //constructor with four Line object arguments (by reference)
        Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm, double &zConst);

        //create a surface object from a suitably formatted text file
        Surface(std::string filename, int Nx_in, int Ny_in);

        Point getPoint(int i, int j);
        int getNx();
        int getNy();
        Line * getNorth();
        Line * getSouth();
        Line * getEast();
        Line * getWest();
        Point getSouthWestCorner();
        Point getSouthEastCorner();
        Point getNorthWestCorner();
        Point getNorthEastCorner();
        void showCoordinates();
        void printCoordinatesToFile(std::string filename);
        
    private:
        Line * myNorth, * mySouth, * myEast, * myWest;
        void interpolate(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm, double &zConst);
        void setPoint(int i, int j, Point p_in);
};
#endif
