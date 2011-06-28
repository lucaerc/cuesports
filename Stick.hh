#ifndef STICK_
#define STICK_

#include <cmath>
#include "Ball.hh"
#include "Vectors.hh"

class Stick {
    
    double _F; //fornito dall'utente
    double _angle; //fornito dall'utente
    double _tau; //e' una costante
    bool _didhit; //ha gia' mandato il colpo?

public:
    
    Stick(double F, double angle);
    ~Stick();
    void hit(Ball & ball);
    bool didsend();
    
    
};

#endif
