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
        Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm);

        //copy constructor

        Point getPoint(int i, int j);
        int getNx();
        int getNy();
        void showCoordinates();
        void printCoordinatesToFile(std::string filename);
        
    private:
        //implementation of tfi
        void interpolate(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest, int &norm);
        void setPoint(int i, int j, Point p_in);
};
#endif
