#ifndef Table_H_
#define Table_H_

const class Table
{
private:
    float atd; //coefficiente di attrito dinamico
    float ats; //coefficiente di attrito statico
    
    float xlenght; //dimensioni tavolo
    float ylenght;
    
public:
    Table(const Table& t){atd=t.atd; ats=t.ats; xlenght=t.xlenght; ylenght=t.ylenght;} //copy constructor
    Table(float X, float Y,float ATD,float ATS){atd=ATD; ats=ATS; xlenght=X; ylenght=Y;}
    ~Table();
    
    bool impactx(const ball b);
    bool impacty(const ball b);
    position poi(const ball b); //punto d'impatto
    velocity newspeed(const ball b);
    //impact(const ball b); data una palla b, restituisce se stessa se non impatta, altrimenti fa puntare b ad una nuova palla con newspeed e poi.
    //Ho bisogno di un metodo adeguato in Ball per farlo
    
    //allimpacts(const ball b); esegue impact in maniera ricorsiva fino a quando non ci sono più impatti possibili
};

#endif
