#ifndef TABLE_
#define TABLE_

#include "Ball.hh"
#include "Cushion.hh"


class Table {
    double _h,_l; //altezza, lunghezza
    Ball * _ball;
    Cushion _down, _up, _left, _right;
    //coefficienti di attrito
    double _mu_s, _mu_v; //_mu_v è l'attrito volvente
    

public:

    Table(h,l,mus,muv);
    Ball & move(double t); //muove la palla che ha come attributo
    void play(Ball & ball);
    void setball(Ball & ball);

};

#endif
