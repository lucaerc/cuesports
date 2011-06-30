#include "Table.hh"

Table::Table(h,l,mus,muv) {
    _h=h;
    _l=l;
    _mu_s=mus;
    _mu_v=muv;
        
}

void Table::setball(Ball & ball){
    delete _ball;
    _ball=ball;
}

Ball & Table::move(double t){
    Velocity v=ball.v();
    Position r=ball.r();
    
    double g=9.81;
    
    if (v.x!=0) {   //M_attrito=m*g*_mu_v/r, F_attrito=m*g*_mu_v/(r*r), a_attrito=g*_mu_v/(r*r) la massa non serve pi
        if (v.x>0){
            r.x = v.x * t - .5*(g*_mu_v*t*t)/(r*r); //questo funziona con t piccolo, altrimenti la palla torna indietro!
            v.x = v.x - (g*_mu_v*t)/(r*r);
            if (v.x<0) v.x=0;
            
        }
        if (v.x<0){
            r.x = v.x * t + .5*(g*_mu_v*t*t)/(r*r);
            v.x = v.x + (g*_mu_v*t)/(r*r);
            if (v.x>0) v.x=0;
        }
    }
    
    else v.x=0;
    
    if (v.y!=0) {
        if (v.y>0){
            r.y = v.y * t - .5*(g*_mu_v*t*t)/(r*r);
            v.y = v.y - (g*_mu_v*t)/(r*r);
            if (v.y<0) v.y=0;
        }
        if (v.y<0){
            r.y = v.y * t + .5*(g*_mu_v*t*t)/(r*r);
            v.y = v.y + (g*_mu_v*t)/(r*r);
            if (v.y>0) v.y=0;
        }
    }
    
    else v.y=0;
    
    new Ball result(r,v);
    return *result;
}
