#ifndef CUSHION_
#define CUSHION_

#include "Ball.hh"

class Cushion { //sponda verticale

double Jassobito; // DA RIVEDERE impulso assorbito nell'urto con la sponda

public:
Cushion();
~Cushion();

void hurt(Ball & other);
};

#endif
