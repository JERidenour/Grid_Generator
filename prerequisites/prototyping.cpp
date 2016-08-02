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

class Surface {

    public:
        Surface();
        ~Surface();
        Surface(Line boundNorth, Line boundSouth, Line boundEast, Line boundWest);
        

};

int main(){

    Line boundSouth = Line(4);
    Line boundNorth = Line(4);
    Line boundEast = Line(4);
    Line boundWest = Line(4);
    Point p;
    double hx = 1.0;
    double hy = 1.0;

    for(int i=0; i<4; i++){

        p.setCoords(i*hx, 0, 0);
        boundSouth.setCoordinate(i, p);

        p.setCoords(i*hx, 3, 0);
        boundNorth.setCoordinate(i, p);

        p.setCoords(3, i*hy, 0);
        boundEast.setCoordinate(i, p);

        p.setCoords(0, i*hy, 0);
        boundWest.setCoordinate(i, p);
    }

    cout << "boundSouth: " << endl;
    boundSouth.showCoords();
    
    cout << "boundNorth: " << endl;
    boundNorth.showCoords();
    
    cout << "boundEast: " << endl;
    boundEast.showCoords();
    
    cout << "boundWest: " << endl;
    boundWest.showCoords();
    

    return 0;
}
