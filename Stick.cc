#include "Stick.hh"


Stick::Stick(double F, double angle){
    _F=F;
    _angle=angle;
    _tau=0.;//valore di tau
    _didsend=false;
}

void Stick::hit(Ball & ball){
    double Jx=F*sin(angle)*_tau; //siccome l'angolo è lungo la verticale, il seno restituisce x e il coseno y
    double Jy=F*cos(angle)*_tau;
    
    Impulse J(Jx,Jy); //questo andrà modificato quando avrai definito Impulse
    
    ball.hurt(J); //trasmette l'impulso alla palla ball
    
    _didsend=true;
    
}
    
bool Stick::didsend(){
    return _didsend;
}

