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
        Surface(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest);

        //copy constructor

        Point getPoint(int i, int j);
        void showCoordinates();
        void printCoordinatesToFile(std::string filename);
        
    private:
        //implementation of tfi
        void interpolate(Line &boundNorth, Line &boundSouth, Line &boundEast, Line &boundWest);
        void setPoint(int i, int j, Point p_in);
};
#endif
