#ifndef POSITION_
#define POSITION_

#include <cmath>

class position {
public:
position(double _x=0, double _y=0) { x=_x; y=_y;}
~position();

double x, y;
};

position::position(double _x, double _y) {
}



#endif

