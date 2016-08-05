#include "domain.h"
#include <iostream>

using namespace std;

Domain::Domain(){

    //default constructor initializes pointers to NULL
    coordinates = NULL;
    corners = NULL;

};

Domain::~Domain(){

    //destructor releases dynamically-allocated memory
    delete [] coordinates;
    delete [] corners;

};

void Domain::setNx(double N_in){Nx = N_in;};
void Domain::setNy(double N_in){Ny = N_in;};
void Domain::setNz(double N_in){Nz = N_in;};

void Domain::setXi(double xi_in){xi = xi_in;};
void Domain::setEta(double eta_in){eta = eta_in;};
void Domain::setZeta(double zeta_in){zeta = zeta_in;};
