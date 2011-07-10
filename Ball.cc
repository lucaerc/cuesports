#include "Ball.hh"

using namespace std;


Ball::Ball(double x=0, double y=0, double vx=0, double vy=0) {
_r=Position(x,y);
_v=Velocity(vx,vy);
_mass=0.16301; // kg 5.5/6 once
_diameter=0.05715; //m
_mu_pp=1.;
}

Ball::Ball(Position r, Velocity v){
    _r=r;
    _v=v;
    _mass=0.16301; // kg 5.5/6 once
    _diameter=0.05715; //m
    _mu_pp=1.;
}


Ball::~Ball() {}

Position Ball::r() { return _r; }
Velocity Ball::v() { return _v; }
double Ball::m() {return _m;}

void Ball::hurt(Impulse J) {
_v.x+=(5./7.)*J.x/_mass;
_v.y+=(5./7.)*J.y/_mass;
//ho trascurato lo spostamento di posizione nel tratto in cui rotola strisciando!
}
//va implementata la possibilità di un urto NON centrale, cioè con distanza h(verticale) rispetto al cm della palla

void Ball::hit(Ball & other) {

}




