#ifndef VECTORS_
#define VECTORS_

#include <cmath>

struct vect2d {
double x, y;
vect2d(double _x=0, double _y=0);
vect2d(vect2d);
~vect2d();

vect2d& operator=(const vect2d &);
vect2d operator+(const vect2d);
double operator*(const vect2d);
};

struct Position : vect2d {

Position(double px=0, double py=0);
Position(Position);
~Position();
};

struct Velocity : vect2d {

Velocity(double vx=0, double vy=0);
Velocity(Velocity);
~Velocity();

Position dr(double dt) { return Position(x*dt,y*dt); } //incremento della posizione data una velocità e un dt
};

struct Impulse : vect2d {

Impulse(double jx=0, double jy=0);
Impulse(Impulse);
~Impulse();

//forse è il caso di fare un metodo che dato un impulso modifichi la velocità, da chiamare in hit ecc? (J=deltaP=m deltav)
};



#endif
