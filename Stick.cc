#include "Stick.hh"
#include <cmath>

Stick::Stick(double J, double angle){
    _J=J;
    _angle=angle;
}

void hit(Ball & ball){
    double Jx=J*sin(angle);
    double Jy=J*cos(angle);
    
    Impulse J(Jx,Jy); //questo andrˆ modificato quando avrai definito Impulse
    
    other.ball(J); //trasmette l'impulso alla palla ball
    
}
    

