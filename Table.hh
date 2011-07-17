#ifndef TABLE_
#define TABLE_

#include "Ball.hh"
#include "Cushion.hh"


class Table {
    double _h,_l; //altezza, lunghezza
    vector<Ball> balls;
    Cushion _down, _up, _left, _right;
    //coefficienti di attrito
    double _mu_s, _mu_v; //_mu_v è l'attrito volvente
    

public:

    Table(h,l,mus,muv);
    int move(double t); //ritorna il numero di palle che non si muovono più
    void play();
    void setball();
    ~Table;
};

#endif
