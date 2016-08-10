#ifndef POINT
#define POINT

#include <string>

class Point{

    public:
        Point();
        ~Point();
        Point(double x_in, double y_in, double z_in);

        //ways other than constructor to set values
        void setPoint(double x_in, double y_in, double z_in);
        void setX(double x_in);
        void setY(double y_in);
        void setZ(double z_in);

        //retrieve values
        double getX();
        double getY();
        double getZ();

        //display values on terminal
        void showPoint(); 

        //return the coordinates as a string
        std::string pointAsString();


    private:
        double x, y, z;

};
#endif
