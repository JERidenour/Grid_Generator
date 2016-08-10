#ifndef LINE
#define LINE

#include "domain.h"
#include "point.h"

class Line : public Domain{

    public:
        Line(int N_in);
        Point getPoint(int i);
        void setPoint(int i, Point p_in);

        void showCoordinates();
        void printCoordinatesToFile(std::string filename);
        void setCorners();

};
#endif
