#include "Table.hh"

Table::Table(h,l,mu,cr) {
    _h=h;
    _l=l;
    _mu_s=mu;
    _cr=cr;
        
}

void Table::setball(Ball & ball){
    delete _ball;
    _ball=ball;
}

Ball & Table::move(double t){
    Velocity v=ball.v();
    Position r=ball.r();
    double m=ball.m();
    double g=9.81;
    
    if (v.x!=0) {
        if (v.x>0){
            r.x = v.x * t - .5*(g*_cr*t*t)/m; //questo funziona con t piccolo, altrimenti la palla torna indietro!
            v.x = v.x - (g*_cr*t)/m;
            if (v.x<0) v.x=0;
            
        }
        if (v.x<0){
            r.x = v.x * t + .5*(g*_cr*t*t)/m;
            v.x = v.x + (g*_cr*t)/m;
            if (v.x>0) v.x=0;
        }
    }
    
    else v.x=0;
    
    if (v.y!=0) {
        if (v.y>0){
            r.y = v.y * t - .5*(g*_cr*t*t)/m;
            v.y = v.y - (g*_cr*t)/m;
            if (v.y<0) v.y=0;
        }
        if (v.y<0){
            r.y = v.y * t + .5*(g*_cr*t*t)/m;
            v.y = v.y + (g*_cr*t)/m;
            if (v.y>0) v.y=0;
        }
    }
    
    else v.y=0;
    
    new Ball result(r,v);
    return *result;
}
