#ifndef VELOCITY_
#define VELOCITY_

#include <cmath>

class velocity {
public:
velocity(double _vx=0, double _vy=0) { x=_vx; y=_vy; }
~velocity();

double x,y;
double dx(double);
double dy(double);
};

#endif

