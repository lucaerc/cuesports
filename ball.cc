#include "ball.hh"
#include <cmath>
#include <iostream>

using namespace std;

position::position(double _x, double _y) { x=_x; y=_y;}
position::~position() {}

velocity::velocity(double _vx, double _vy) { x=_vx; y=_vy; }
velocity::~velocity() {}

ball::ball(double x, double y) {
_r=position(x,y);
_v=velocity();
weight=1.;
diameter=57.15;
}

void ball::setv(double vx, double vy) {
_v=velocity(vx,vy);
}

ball::~ball() {}

double ball::S() {return diameter*3.14;}

void ball::move(double t) {
_r.x+=_v.dx(t);
_r.y+=_v.dy(t);
}


void ball::hit(double F, double angle) {

}

void ball::show() {
cout << "r = (" <<_r.x << ", " << _r.y << ")\nv = (" <<_v.x << ", " << _v.y << ")" << endl;
}



