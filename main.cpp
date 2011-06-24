
#include "ball.hh"

using namespace std;

int main () {

ball prova(1,1);
prova.show();
cout << "--------------------------\n";
prova.setv(2,0);
prova.move(2);
prova.show();
return 0;
}
