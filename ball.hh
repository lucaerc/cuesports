#ifndef BALL_
#define BALL_

#include <iostream>
#include <cmath>
#include<cstdlib>


struct position {
double x, y;
position(double _x=0, double _y=0);
~position();

position operator=(position &);
position operator+(position &); // da usare in move, per fare r=r0+dr
};

struct velocity {
double x,y;

velocity(double _vx=0, double _vy=0);
~velocity();

double dx(double t) { return x*t; }
double dy(double t) { return y*t; }
position dr(double t) { return position(x*t,y*t); }

velocity operator=(position &);
};

class ball {
position _r;
velocity _v;
double weight, diameter;
public:
ball(double x=0, double y=0);
~ball();

double S();

void hit(double, double); // i parametri sono F e angle, questa funzione chiama setv con parametro F*tau/weight
void setv(double, double); 
void move(double t);
position r();//è scomodo chiamare .r().x, forse è meglio dichiarare public _r...
velocity v();//idem

};

#endif

