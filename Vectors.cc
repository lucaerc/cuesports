
#include "Vectors.hh"

//-------------------------------------------base class--------------------------------------------------
vect2d::vect2d(double _x, double _y) { x=_x; y=_y;}
vect2d::vect2d(const vect2d & other) { x=other.x; y=other.y; }
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
Position::Position(const Position & other) { x=other.x); y=other.y; } //fare initialization lists sui copy constructor?
Position::~Position() { }

double Position::distancefrom(Position p2) {
    return(sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y)));
}


Velocity::Velocity(double vx=0, double vy=0) : vect2d(vx, vy) { }
Velocity::Velocity(const Velocity & other) {y=other.y; x=other.x; }
Velocity::~Velocity() {}

bool Velocity::stopped(){
    if (x=0 and y=0) return TRUE;
    else return FALSE;
}


Impulse::Impulse(double jx=0, double jy=0) :vect2d(jx, jy) { }
Impulse::Impulse(const Impulse & other) {y=other.y; x=other.x; }
Impulse::~Impulse();

