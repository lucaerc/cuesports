
#ifndef TAVOLO_H_
#define TAVOLO_H_

const class Tavolo
{
private:
    float atd; //coefficiente di attrito dinamico
    float ats; //coefficiente di attrito statico
    
    float xlenght; //dimensioni tavolo
    float ylenght;
    
public:
    Tavolo(float X, float Y,float ATD,float ATS){atd=ATD; ats=ATS; xlenght=X; ylenght=Y;}
    ~Tavolo();
    
    bool impactx(const position pos const velocity v);
    bool impacty(const position pos ,const velocity v);
    position poi(const position pos, const velocity v); //punto d'impatto
    velocity newspeed(const position pos,const velocity v);
    
};

#endif