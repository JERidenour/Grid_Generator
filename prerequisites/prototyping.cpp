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

class Domain {

    public:
        Domain();
        ~Domain();
        virtual void showCoordinates()=0;

    protected:
        int Nx, Ny, Nz;
        double xi, eta, zeta;
        Point * coordinates, * corners;

};

Domain::Domain(){ coordinates = NULL; corners = NULL;} //set to null pointer if default is called
Domain::~Domain(){ delete [] coordinates; delete [] corners;} //release dynamic memory

class Line : public Domain {

    public:
        Line(int N);
        void setPoint(int i, Point p_in);
        void showCoordinates();
};

void Line::showCoordinates(){

    for(int i = 0; i < Nx; i++){

        cout << "(" << coordinates[i].getX() << ", " << coordinates[i].getY() << ", " << coordinates[i].getZ() << ")" << endl;

    }
}

Line::Line(int N){

    coordinates = new Point[N];
    corners = new Point[2];
    Nx = N; 
    Ny = 0;
    Nz = 0; 

}

void Line::setPoint(int i, Point p_in){

    coordinates[i] = p_in;

}

int main(){

    cout << "creating Point objects" << endl;
    Point p1, p2, p3, p4, p5;
    p1.setCoords(0.0, 0.0, 0.0);
    p2.setCoords(1.0, 1.0, 0.0);
    p3.setCoords(2.0, 2.0, 0.0);
    p4.setCoords(3.0, 3.0, 0.0);
    p5.setCoords(4.0, 4.0, 0.0);

    cout << "initializing Line" << endl;
    Line L = Line(5);   

    cout << "setting points..." << endl;
    L.setPoint(0, p1);
    L.setPoint(1, p2);
    L.setPoint(2, p3);
    L.setPoint(3, p4);
    L.setPoint(4, p5);

    cout << "calling showCoordinates()..." << endl;
    L.showCoordinates();

    return 0;
}
