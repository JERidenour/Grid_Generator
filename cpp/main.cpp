#include "point.h"
#include "line.h"
#include <iostream>

using namespace std;

int main(){

    int N = 10;
    double h = 0.1;

    Line L = Line(N);
    Point p;

    for(int i=0; i<N; i++){

        p.setPoint(0.0 + i*h, 1.0, 2.0);
        L.setPoint(i, p);

    } 


    L.setCorners();
    L.showCoordinates();
    L.printCoordinatesToFile("testOutput.txt");

    cout << endl;
    cout << endl;

    Point q = L.getPoint(5);
    q.showPoint();

    return 0;
}
