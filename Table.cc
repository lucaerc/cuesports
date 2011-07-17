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

int Table::move(double t){
    int size=balls.size();
    int stopped=0;
    for (int i=0; i<size; i++) {
        Velocity v=balls.at(i).v();
        Position r=balls.at(i).r();
        
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
        if (balls.at(i).v().stopped=TRUE and v.stopped=FALSE) stopped--;
        if (balls.at(i).v().stopped=FALSE and v.stopped=TRUE) stopped++;

        balls.at(i)=new Ball result(r,v);
        
    }
    return stopped;
}

void Table::play() {
    double t=0;
    int stopped=0;
    for (t=0;stopped<balls.size(); t=t+0.01) {
        stopped=move(); //controlla che tutte le palle non siano ferme
        for (int i=0; i<balls.size(); i++) {
            if (balls.at(i).r().x=0) _left.hurt(_ball);
            if (balls.at(i).x=_l) _right.hurt(_ball);
            if (balls.at(i).y=0) _down.hurt(_ball);
            if (balls.at(i).y=_h) _up.hurt(_ball);
            for (int j=0; j<balls.size(); j++) { //controlla se sono pi vicini della somma dei raggi
                if (j!=i){
                    if (balls.at(i).distancefrom(balls.at(j)<= (.5*balls.at(i).d()+.5*balls.at(j).d())) {
                        balls.at(i).hit(balls.at(j));
                    }
                }
            }
        }
}
    

                        
                        //se le palle sono ad una distanza minore della somma dei loro raggi, c' impatto
                        
                        
                