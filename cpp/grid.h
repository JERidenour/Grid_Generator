#ifndef GRID
#define GRID

#include "point.h"
#include "surface.h"
#include <string>

class Grid : public Domain{

    public: 
        //default constructor
        Grid() : Domain(){};
    
        //constructor with six surface elements
        Grid(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, Surface &boundWest, Surface &boundFront, Surface &boundBack);

    Point getPoint(int i, int j, int k);
    void showCoordinates();
    void printCoordinatesToFile(std::string filename);

    private:
        void interpolate(Surface &boundNorth, Surface &boundSouth, Surface &boundEast, Surface &boundWest, Surface &boundFront, Surface &boundBack);

        void setPoint(int i, int j, int k, Point p_in);
};
#endif