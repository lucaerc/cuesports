#ifndef BALL_
#define BALL_

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Vectors.hh"

class Ball {
    Position _r;
    Velocity _v;
    double _mass, _diameter, _mu_pp;
public:
    Ball(double x=0, double y=0, double vx=0, double vy=0);
    Ball(Position r, Velocity v);
    ~Ball();

    Position r();
    Velocity v();
    double m();
    
    void hurt(Impulse J); //è unico per qualsiasi tipo
    void hit(Ball & other);
};

#endif

