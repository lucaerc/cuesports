
class Stick {
double _J; //fornito dall'utente
double _angle; //fornito dall'utente
double _tau; //è una costante

public:
Stick(double J, double angle);
~Stick();

void hit(Ball & ball);
};
