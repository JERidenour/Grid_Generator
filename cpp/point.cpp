#include "point.h"
#include <iostream>
#include <sstream>

using namespace std;

Point::Point(){};
Point::~Point(){};
Point::Point(double x_in, double y_in, double z_in){

    x = x_in;
    y = y_in;
    z = z_in;

};

void Point::setPoint(double x_in, double y_in, double z_in){

    x = x_in;
    y = y_in;
    z = z_in;

};

void Point::setX(double x_in){x = x_in;};
void Point::setY(double y_in){y = y_in;};
void Point::setZ(double z_in){z = z_in;};

double Point::getX(){return x;};
double Point::getY(){return y;};
double Point::getZ(){return z;};

void Point::showPoint(){

    cout << "(" << x << ", " << y << ", " << z << ")" << endl;

};

string Point::pointAsString(){

    ostringstream strs;
    strs <<  x << "\t" << y << "\t" << z << "\t";
    
    return strs.str();
};
