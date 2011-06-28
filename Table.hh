#ifndef TABLE_
#define TABLE_

#include "Ball.hh"
#include "Cushion.hh"


class Table {
Ball * _ball;
Cushion _down, _up, _left, _right;
//coefficienti di attrito
double _mu_s, _mu_d, _mu_v;

public:

Ball & move(Ball & moved, double t);
void play(Ball & ball);

};

#endif
