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
    double _mu_s, _mu_v; //_mu_v è l'attrito volvente
    

public:

    Table(double h, double l, double mus, double muv);
    int move(double t); //ritorna il numero di palle che non si muovono più
    void play();
    Ball setball(Ball);
    ~Table();
};

#endif
