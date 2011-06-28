#include "Ball.hh"

using namespace std;


Ball::Ball(double x, double y) {
_r=Position(x,y);
_v=Velocity();
weight=163.01; // g 5.5/6 once
diameter=57.15; //mm
}

Ball::~Ball() {}

Position Ball:r() { return _r; }
Velocity Ball:v() { return _v; }

void Ball::hit(double F, double angle) {

}

void Ball::move(double t) {
_r=_r+dr(t);
//implementare l'attrito; man mano che mi muovo, v deve (logicamente) diminuire.
}

/*
void Ball::setv(double vx, double vy) {
_v=Velocity(vx,vy);
}
*/




