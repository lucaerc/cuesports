
#include "Vectors.hh"

//-------------------------------------------base class--------------------------------------------------
vect2d::vect2d(double _x, double _y) { x=_x; y=_y;}
vect2d::vect2d(vect2d other) { x=other.x; y=other.y; }
vect2d::~vect2d() { }

vect2d& vect2d::operator=(const vect2d & other) {
	if (this!=&other) {
	x=other.x;
	y=other.y;
	}
return *this;
}

vect2d vect2d::operator+(const vect2d obj) { return vect2d(x+obj.x,y+obj.y); }

double vect2d::operator*(const vect2d obj) { return vect2d(x*obj.x+y*obj.y); }

vect2d vect2d::operator/(const double a); { return vect2d(x/a,y/a); }

//----------------------------------------derived classes------------------------------------------------

Position::Position(double px=0, double py=0): vect2d(px, py) { }
Position::Position(Position other) { x=other.x); y=other.y; } //fare initialization lists sui copy constructor?
Position::~Position() { }


Velocity::Velocity(double vx=0, double vy=0) : vect2d(vx, vy) { }
Velocity::Velocity(Velocity other) {y=other.y; x=other.x; }
Velocity::~Velocity() {}


Impulse::Impulse(double jx=0, double jy=0) :vect2d(jx, jy) { }
Impulse::Impulse(Impulse other) {y=other.y; x=other.x; }
Impulse::~Impulse();

