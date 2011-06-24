#ifndef BALL_
#define BALL_

#include <iostream>
#include <cmath>
#include<cstdlib>


struct position {
double x, y;
position(double _x=0, double _y=0);
~position();
};

struct velocity {
double x,y;

velocity(double _vx=0, double _vy=0);
~velocity();

double dx(double t) { return x*t; }
double dy(double t) { return y*t; }
position dr(double t) { return position(x*t,y*t); }
};

class ball {
position _r;
velocity _v;
double weight, diameter;
public:
ball(double x=0, double y=0);
~ball();

double S();

void hit(double, double);
void setv(double, double);
void move(double t);


void show();
};

#endif

