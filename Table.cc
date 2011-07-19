#include "Table.hh"

using namespace std; 

Table::Table(double h, double l, double mus, double muv) {
    _h=h;
    _l=l;
    _mu_s=mus;
    _mu_v=muv;
        
}

Ball Table::setball(Ball ball){ return ball; }

int Table::move(double t){
    int size=balls.size();
    int stopped=0;
    for (int i=0; i<size; i++) {
        Velocity v=balls[i].v();
        Position r=balls[i].r();
        
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

        if (balls[i].v().stopped()==true and v.stopped()==false) stopped--;
        if (balls[i].v().stopped()==false and v.stopped()==true) stopped++;

        
        balls[i]=setball(Ball(r,v));
        
    }
    return stopped;
}

void Table::play() {
    double t=0;
    int stopped=0;
    for (t=0;stopped<balls.size(); t+=0.01) {
        stopped=move(t); //controlla che tutte le palle non siano ferme
        for (int i=0; i<balls.size(); i++) {
            if (balls[i].r().x=0) _left.hurt(_ball);
            if (balls[i].x=_l) _right.hurt(_ball);
            if (balls[i].y=0) _down.hurt(_ball);
            if (balls[i].y=_h) _up.hurt(_ball);
            for (int j=0; j<balls.size(); j++) { //controlla se sono pi vicini della somma dei raggi
                if (j!=i){
                    if (balls[i].distancefrom(balls[j]<= (.5*balls[i].d()+.5*balls[j].d())) {
                        balls[i].hit(balls[j]);
                    }
                }
            }
        }
}
    

                        
                        //se le palle sono ad una distanza minore della somma dei loro raggi, c' impatto
                        
                        
                
