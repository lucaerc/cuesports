#ifndef CUSHION_
#define CUSHION_

#include "Ball.hh"

class Cushion { //sponda verticale

    double percentage; // La sponda assorbe una percentuale di energia cinetica
    double xchange;
    double ychange;
    Table * table;

public:
    Cushion(double xc, double yc, double p=0.3, table * tab);
    ~Cushion();

    void hurt(Ball & ball);
};

#endif
