#include "Ball.hh"

using namespace std;


Ball::Ball(double x, double y, double vx, double vy, table & tab) {
    r=Position(x,y);
    v=Velocity(vx,vy);
    _mass=0.16301; // kg 5.5/6 once
    _diameter=0.05715; //m
    _mu_pp=1.;
    table=tab;
}

Ball::Ball(Position R, Velocity V, table & tab){
    r=R;
    v=V;
    _mass=0.16301; // kg 5.5/6 once
    _diameter=0.05715; //m
    _mu_pp=1.;
    table=tab;
}


Ball::~Ball() {}

Position Ball::r() { return r; }
Velocity Ball::v() { return v; }
double Ball::m() {return _mass;}
double Ball::d() {return _diameter;}

bool Ball::didstop() {
    if (v.x=0 and v.y=0) return TRUE;
    else return FALSE;
    }

double Ball::distancefrom(Ball b) {
    return(sqrt((r.x-b.r().x)*(r.x-b.r().x)+(r.y-b.r().y)*(r.y-b.r().y)));
}

double Ball::distancefrom(Position p) {
    return(sqrt((r.x-p.x)*(r.x-p.x)+(r.y-p.y)*(r.y-p.y)));
}
void Ball::hurt(Impulse J) {
    stopped=false;
    v.x+=(5./7.)*J.x/_mass;
    v.y+=(5./7.)*J.y/_mass;
    this.move();
}

//va implementata la possibilità di un urto NON centrale, cioè con distanza h(verticale) rispetto al cm della palla

void Ball::move(double delta) {
    const double g=9.81;
    
    if (v.x!=0) {   //M_attrito=m*g*table.mu()/r, F_attrito=m*g*table.mu()/(r*r), a_attrito=g*table.mu()/(r*r) la massa non serve più
        if (v.x>0){
            r.x = v.x * delta - .5*(g*table.mu()*delta*delta)/(r*r); //questo funziona con t piccolo, altrimenti la palla torna indietro!
            v.x = v.x - (g*table.mu()*delta)/(r*r);
            if (v.x<0) v.x=0;
            
        }
        if (v.x<0){
            r.x = v.x * delta + .5*(g*table.mu()*delta*delta)/(r*r);
            v.x = v.x + (g*table.mu()*delta)/(r*r);
            if (v.x>0) v.x=0;
        }
    }
    
    else v.x=0;
    
    if (v.y!=0) {
        if (v.y>0){
            r.y = v.y * delta - .5*(g*table.mu()*delta*delta)/(r*r);
            v.y = v.y - (g*table.mu()*delta)/(r*r);
            if (v.y<0) v.y=0;
        }
        if (v.y<0){
            r.y = v.y * delta + .5*(g*table.mu()*delta*delta)/(r*r);
            v.y = v.y + (g*table.mu()*delta)/(r*r);
            if (v.y>0) v.y=0;
        }
    }
    
    else v.y=0;
    
    table.check(this);
    
        
}

void Ball::hit(Ball & other) {

}




