#ifndef TABLE_
#define TABLE_

#include "Ball.hh"
#include "Cushion.hh"
#include <vector>

class Table {
    double _h,_l; //altezza, lunghezza
    std::vector <Ball> balls;
    Cushion _down, _up, _left, _right;
    //coefficienti di attrito
    double _mu_v; //_mu_v è l'attrito volvente
    

public:

    Table(double h, double l, double muv);
    ~Table();
    void addball(double x=0, double y=0, double vx=0, double vy=0);
    void addball(Position R, Velocity V);
    double mu();
    
    void check(Ball b);
    void play(double delta=0.01);
    
};

#endif
