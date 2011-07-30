#include "Table.hh"

using namespace std; 

Table::Table(double h, double l, double mus, double muv) {
    _h=h;
    _l=l;
    _mu_s=mus;
    _mu_v=muv;
        
}
double Table::mu() {
    return _mu_v;
}

void Table::addball(double x=0, double y=0, double vx=0, double vy=0){
    Ball b(x,y,vx,vy,*this); //assegna se stesso come tavolo
    balls.pushback(b);
}

void addball(Position R, Velocity V){
    Ball b(R,V,*this); //assegna se stesso come tavolo
    balls.pushback(b);
}

void Table::check(Ball b) {
    for (int i=0; i<=balls.size(); i++) {
        if (*b=*balls[i]); //dovrebbe escludere l'autocolpo
        else {
            if (b.distancefrom(balls[i]) < (.5*balls[i].d()+.5*b.d())) b.hit(balls[i]); 
        }
    }
    if (b.r().x=0) _left.hurt(b);
    if (b.r().x=_l) _right.hurt(b);
    if (b.r().y=0) _down.hurt(b);
    if (b.r().x=_h) _up.hurt(b);
}
                    
void Table::play(double delta) {
    int stopped=0;
    do {
        stopped=0;
        for (int i=0; i<=balls.size(); i++) {
            balls[i].move(delta); //prende il delta di default
            if (balls[i].didstop()==TRUE) stopped++;
        }
    } while (stopped<balls[i].size());
        
}


                        
                
