#include "Cushion.hh"

Cushion::Cushion(double xc, double yc, double p,table * tab) {
    percentage=p;
    xchange=xc;
    ychange=yc;
    table=tab;
}

void Cushion::hurt(Ball & ball) {
    Velocity v2;
        
    v2.x=ball.v().x * xchange * sqrt(percentage); //radice quadrata perché percentuale di energia cinetica
    v2.y=ball.v().y * ychange * sqrt(percentage); 
    
    Ball newball(ball.r(),v2,table);
    delete *ball;
    ball = *newball;
    
}