#include "Table.hh"

using namespace std; 

Table::Table(double h, double l, double mus, double muv) {
    _h=h;
    _l=l;
    _mu_s=mus;
    _mu_v=muv;
        
}

Ball Table::setball(Ball ball){ return ball; }

int Table::move(double t){
    int size=balls.size();
    int stopped=0;
    for (int i=0; i<size; i++) {
        Velocity v=balls[i].v();
        Position r=balls[i].r();
        
        double g=9.81;
        
        if (v.x!=0) {   //M_attrito=m*g*_mu_v/r, F_attrito=m*g*_mu_v/(r*r), a_attrito=g*_mu_v/(r*r) la massa non serve più
            if (v.x>0){
                r.x = v.x * t - .5*(g*_mu_v*t*t)/(r*r); //questo funziona con t piccolo, altrimenti la palla torna indietro!
                v.x = v.x - (g*_mu_v*t)/(r*r);
                if (v.x<0) v.x=0;
                
            }
            if (v.x<0){
                r.x = v.x * t + .5*(g*_mu_v*t*t)/(r*r);
                v.x = v.x + (g*_mu_v*t)/(r*r);
                if (v.x>0) v.x=0;
            }
        }
        
        else v.x=0;
        
        if (v.y!=0) {
            if (v.y>0){
                r.y = v.y * t - .5*(g*_mu_v*t*t)/(r*r);
                v.y = v.y - (g*_mu_v*t)/(r*r);
                if (v.y<0) v.y=0;
            }
            if (v.y<0){
                r.y = v.y * t + .5*(g*_mu_v*t*t)/(r*r);
                v.y = v.y + (g*_mu_v*t)/(r*r);
                if (v.y>0) v.y=0;
            }
        }
        
        else v.y=0;

        if (balls[i].v().stopped()==true and v.stopped()==false) stopped--;
        if (balls[i].v().stopped()==false and v.stopped()==true) stopped++;

        
        balls[i]=setball(Ball(r,v));
        
    }
    return stopped;
}

void Table::play() { //il vecchio Play è in oldtable
    int size=balls.size();
    int dist=0;
    for (int i=0; i<size; i++) {
        for (int i=0; j<size; j++){
            dist=abs(distballs[j].r().y-((balls[i].r().y+(balls[i]v().y/balls[i]v().x)*(balls[j].r().x-balls[i].r().x)))); //abs valore assoluto (esiste?)
            if dist=<(.5*balls[i].d()+.5*balls[j].d()){
                //TROVA IL TEMPO E MOVE
            }
            else {}  //CONDIZIONI DELL'URTO CON SPONDE, TROVA TEMPO E MOVE
//attenzione, questo funziona bene se si muove una palla alla volta
            
            }
  }
    

                        
                        //se le palle sono ad una distanza minore della somma dei loro raggi, c'è impatto
                        
                        
                
