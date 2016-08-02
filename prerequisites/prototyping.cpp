#include <iostream>

using namespace std;

class Point {

    public:
        Point(double x_in, double y_in, double z_in);  
        Point();
        ~Point();
        double getX();
        double getY();
        double getZ();
        void setCoords(double x_in, double y_in, double z_in);  

    private:
        double x, y, z;

};

Point::Point(double x_in, double y_in, double z_in){

    x = x_in;
    y = y_in;
    z = z_in;

}

Point::Point(){}
Point::~Point(){}

double Point::getX(){ return x;}
double Point::getY(){ return y;}
double Point::getZ(){ return z;}

void Point::setCoords(double x_in, double y_in, double z_in){

    x = x_in;
    y = y_in;
    z = z_in;

}  

class Line {

    public:
        Line();
        ~Line();
        Line(int N_in);
        void setCoordinate(int i, Point p);
        void showCoords();

    private:
        int N;
        Point * coordinates;

};

Line::Line(){ coordinates = NULL;}
Line::~Line(){ delete [] coordinates;}
Line::Line(int N_in ){

    N = N_in;
    coordinates = new Point[N];

}

void Line::setCoordinate(int i, Point p){
    coordinates[i] = p;
}

void Line::showCoords(){

    for(int j = 0; j < N; j++){

        cout << "(" << coordinates[j].getX() << ", " << coordinates[j].getY() << ", "  << coordinates[j].getZ() << ")" << endl;    

    }

}

int main(){

    Point a = Point(0.0, 0.0, 0.0);
    Point b = Point(1.1, 1.1, 1.1);
    
    Line l = Line(2);
    l.setCoordinate(0, a);
    l.setCoordinate(1, b);
    l.showCoords();

    

    return 0;
}
