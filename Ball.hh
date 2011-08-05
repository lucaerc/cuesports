#ifndef BALL_
#define BALL_

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Vectors.hh"
#include "Table.hh"

class Ball {
    Position r;
    Velocity v;
    double _mass, _diameter, _mu_pp;
    Table * table;
    
public:
    Ball(double x=0, double y=0, double vx=0, double vy=0, Table * tab);
    Ball(Position R, Velocity V, table * tab);

    ~Ball();

    Position r();
    Velocity v();
    bool didstop(); //TRUE se fermo
    double m();
    double d(); //restituisce diametro
    double distancefrom(Ball b); //distanza in modulo da un'altra palla
    double distancefrom(Position p);
    
    void hurt(Impulse J); //è unico per qualsiasi tipo
    void hit(Ball & other);
    void move(double delta=0.01); //delta è l'intervallo di ogni fotogramma
};

#endif

