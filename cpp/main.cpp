#include "point.h"
#include <iostream>

using namespace std;

int main(){

    Point p, q;
    
    p.setPoint(0.0, 0.0, 0.0);
    p.showPoint();
    
    q.setX(1.0);
    q.setY(1.0);
    q.setZ(1.0);
    cout << "(" << q.getX() << ", " << q.getY() << ", " << q.getZ() << ")" << endl;


    return 0;
}
