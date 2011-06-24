#ifndef Table_CPP_
#define Table_CPP_
#include "Table.h"
#include <cmath>

bool Table::impactx(const ball b)
{   
    position pos=b.r();
    velocity v=b.v();
    float xvelocity=v.x; //copiamo le variabili perché dobbiamo farci delle operazioni senza modificarne il valore
    float xposition=pos.x;
   
    //Viene calcolata la posizione all'istante t della palla, considerato l'attrito, da t=0 fino a t tale che la velocità si annulla o torna negativa
    if (v.x>0){
        for (int t=0; xvelocity>0; t++) {  
            xposition=pos.x+(v.x*t)-(.5*atd*t*t);
            if (xposition>=xlenght) return true;
            xvelocity=x.v-atd*t;
        }
    }
    //se invece la velocità parte verso le coordinate negative
    
    if (v.x<0){
        for (int t=0; xvelocity<0; t++) {  
            xposition=pos.x+(v.x*t)+(.5*atd*t*t);
            if (xposition<=0) return true;
            xvelocity=x.v+atd*t;
        }
    }
    return false;
}

bool Table::impacty(const ball b)
{
    position pos=b.r();
    velocity v=b.v();
    //copiamo le variabili perché dobbiamo farci delle operazioni senza modificarne il valore
    float yvelocity=v.y;
    float yposition=pos.y;
    
    //Viene calcolata la posizione all'istante t della palla, considerato l'attrito, da t=0 fino a t tale che la velocità si annulla o torna negativa
    if (v.y>0){
        for (int t=0; yvelocity>0; t++) {  
            yposition=pos.y+(v.y*t)-(.5*atd*t*t);
            if (yposition>=ylenght) return true;
            yvelocity=y.v-atd*t;
        }
    }
    //se invece la velocità parte verso le coordinate negative
    
    if (v.y<0){
        for (int t=0; yvelocity<0; t++) {  
            yposition=pos.y+(v.y*t)+(.5*atd*t*t);
            if (yposition<=0) return true;
            yvelocity=y.v+atd*t;
        }
    }
    return false;
}

position Table::poi(const ball b)
{
    position pos=b.r();
    velocity v=b.v();
    if (impactx(b)==TRUE)
    {
        float t;
        float x;
        if (v.x>0){ //l'impatto è per x=xlenght
            t=(sqrt((2*atd*xlenght)-(2*atd*pos.x)+(v.x*v.x))-v.x)/atd; //calcola il tempo d'impatto
            x=xlenght;
        }
        if (v.x<0){ //l'impatto è per x=0
            t=(-v.x+sqrt(v.x*v.x - 2*atd*pos.x))/atd;
            x=0;
        }
            
    float y=pos.y+v.y*t-(copysign(1.,v.y))*.5*atd*t*t; //la posizione y dell'impatto, copysign dice se v.y è positiva o negativa
        
        position poi(x,y); 
        return poi;
    }
    
    if (impacty(b)==TRUE)
    {
        float t;
        if (v.y>0){ 
            t=(sqrt((2*atd*ylenght)-(2*atd*pos.y)+(v.y*v.y))-v.y)/atd; //calcola il tempo d'impatto
            y=ylenght;
        }
        
        if (v.y<0){ 
            t=(-v.y+sqrt(v.y*v.y - 2*atd*pos.y))/atd;
            y=0;
        }
        
        float x=pos.x+v.x*t-(copxsign(1.,v.x))*.5*atd*t*t;
        position poi(x,y); 
        return poi;
    }
    
    if (impactx(b)==false and impacty==false) //Nessun impatto
    {
        throw NO_IMPACT;
        return pos;
    }
    
}

velocity Table::newspeed(const ball b)
{
    position pos=b.r();
    velocity v=b.v();
    
    if (impactx(b)==FALSE and impacty(b)==false) return v; //se non c'è impatto, la velocità rimane la stessa
    
    float vx,vy;
    
    if(impactx(b)=true)
    {   
        float toi;
        if (v.x>0)toi=(sqrt((2*atd*xlenght)-(2*atd*pos.x)+(v.x*v.x))-v.x)/atd; 
        if (v.x<0)toi=(-v.x+sqrt(v.x*v.x - 2*atd*pos.x))/atd;
        
        vx=v.x-(copysign(1.,v.x))*atd*toi;
        vx=-vx; //la velocità diventa opposta urto anelastico m->M M>>m
        if (v.y!=0) vy=v.y-(copysign(1.,v.y))*atd*toi;
        if (v.y=0) vy=0
        velocity newspeed(vx,vy);
        return newspeed;
    }
    
    if(impacty(b)=true)
    {   
        float toi;
        if (v.y>0)toi=(sqrt((2*atd*ylenght)-(2*atd*pos.y)+(v.y*v.y))-v.y)/atd; 
        if (v.y<0)toi=(-v.y+sqrt(v.y*v.y - 2*atd*pos.y))/atd;
        
        vy=v.y-(copysign(1.,v.y))*atd*toi;
        vy=-vy; //la velocità diventa opposta urto anelastico m->M M>>m
        
        if (v.x!=0) vx=v.x-(copxsign(1.,v.x))*atd*toi;
        if (v.x=0) vx=0;
        velocity newspeed(vx,vy);
        return newspeed;
    }
                            
}

#endif