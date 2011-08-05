//
//  main.cpp
//  
//
//  Created by Federico D'Ambrosio on 31/07/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Ball.hh"
#include "Cushion.hh"
#include "Stick.hh"
#include "Table.hh"
#include "Vectors.hh"

using namespace std;

int main() {
    cout<<"Tavolo da biliardo"<<endl;
    double h,l, muv;
    cout<<"Dimensioni del tavolo, altezza(m):";
    cin>>h;
    cout<<"Lunghezza(m):";
    cin>>l;
    cout<<"Coefficiente di attrito volvente:";
    cin>>muv;
    Table tab(h,l,muv);
    tab.addball();
    double n, ang;
    cout<<"Colpo alla palla, forza(N):";
    cin>>n;
    cout<<"Angolo:";
    cin>>ang;
    Stick firststrike(n,ang);
    cout<<"Bum:"<<endl;
    firststrike.hit(table.balls[0]);
    cout<<"Ora la palla è: "<<balls[0].r().x<<","<<balls[0].r().y<<"."<<endl;
    return 0;
    
    
}