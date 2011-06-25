#include "Ball.hh"

using namespace std;

Position::Position(double _x, double _y) { x=_x; y=_y;}
Position::Position(Position other) { x=other.x; y=other.y; }
Position::~Position() {}

Position& Position::operator=(const Position & other) {
	if (this!=&other) {
	x=other.x;
	y=other.y;
	}
return *this;
}

Position Position::operator+(const Position obj) { return Position(x+obj.x,y+obj.y); }

Velocity::Velocity(double _vx, double _vy) { x=_vx; y=_vy; }
Velocity::Velocity(Velocity) {y=other.y; x=other.x; }
Velocity::~Velocity() {}

Velocity& Velocity::operator=(const Velocity & other) {
	if (this!=&other) {
	x=other.x;
	y=other.y;
	}
return *this;
}

Ball::Ball(double x, double y) {
_r=Position(x,y);
_v=Velocity();
weight=163.01; // g 5.5/6 oncie
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


