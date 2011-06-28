#include "Ball.hh"

using namespace std;


Ball::Ball(double x, double y) {
_r=Position(x,y);
_v=Velocity();
_mass=163.01; // g 5.5/6 once
_diameter=57.15; //mm
_mu_pp=1.;
}

Ball::~Ball() {}

Position Ball::r() { return _r; }
Velocity Ball::v() { return _v; }

void Ball::hurt(Impulse J) {
_v.x+=(5./7.)*J.x/_mass;
_v.y+=(5./7.)*J.y/_mass;
//ho trascurato lo spostamento di posizione nel tratto in cui rotola strisciando!
}
//va implementata la possibilità di un urto NON centrale, cioè con distanza h(verticale) rispetto al cm della palla

void Ball::hit(Ball & other) {

}




