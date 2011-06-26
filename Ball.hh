#ifndef BALL_
#define BALL_

#include <iostream>
#include <cmath>
#include<cstdlib>


struct Position {
double x, y;
Position(double _x=0, double _y=0);
Position(Position);
~Position();

Position& operator=(const Position &);
Position operator+(const Position); // da usare in move, per fare r=r0+dr
};

struct Velocity {
double x,y;

Velocity(double _vx=0, double _vy=0);
Velocity(Velocity);
~Velocity();

double dx(double t) { return x*t; }
double dy(double t) { return y*t; }
Position dr(double t) { return Position(x*t,y*t); }

Velocity& operator=(const Velocity &);
};

class Ball {
Position _r;
Velocity _v;
double weight, diameter;
public:
Ball(double x=0, double y=0);
~Ball();

Position r();
Velocity v();

void hit(double F, double angle); // i parametri sono F e angle, deve settare la velocità a F*tau/weight (??)
//void setv(double, double); --------non dobbiamo mai settare direttamente la velocità, ma solo tramite interazioni di tipo hurt hit--------------
void move(double t);
void hurt(Ball & other); //deve semplicemente modificare le velocità, non le posizioni, e venir chiamato da Table quando le r() di due balle si sovrappongono
void hurt(Cushion & other);

};

#endif

