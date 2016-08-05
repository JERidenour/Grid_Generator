#ifndef DOMAIN
#define DOMAIN

#include "point.h"
#include <string>

class Domain{

    public:
        Domain();
        ~Domain();

        void setNx(double N_in);
        void setNy(double N_in);
        void setNz(double N_in);

        virtual void showCoordinates()=0;
        virtual void printCoordinatesToFile(std::string filename)=0;
        virtual void setCorners()=0;


    protected:
        int Nx, Ny, Nz;
        double xi, eta, zeta;
        Point * coordinates, * corners;

        void setXi(double xi_in);
        void setEta(double eta_in);
        void setZeta(double zeta_in);

};
#endif
