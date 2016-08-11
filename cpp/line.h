#ifndef LINE
#define LINE

#include "domain.h"
#include "point.h"

class Line : public Domain{

    public:
        //default constructor
        Line() : Domain(){};

        //construct with N_in allocated point slots
        Line(int N_in);

        //copy constructor
        Line(const Line& Line_in);
    
        //return point at index i
        Point getPoint(int i);

        //set point at index i to point p_in
        void setPoint(int i, Point p_in);

        //return the number of elements in the line 
        int getN();

        //show points on terminal
        void showCoordinates();

        //print coordinates to file filename
        void printCoordinatesToFile(std::string filename);
        
        //set corner values (for use in interpolation)
        void setCorners();

};
#endif
