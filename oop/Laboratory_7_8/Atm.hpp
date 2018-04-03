//
//  Atm.hpp
//  Laboratory_7_8
//
//  Created by Timofte Ciprian Andrei on 03/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Atm_hpp
#define Atm_hpp

#include <stdio.h>

class Atm{
public:
    Atm();
    Atm(char* n, int c, int p);
    Atm(Atm & a);
    ~Atm();
    
    char* getName();
    int getCnp();
    int getPin();
    void setCnp(int cnp);
    void setPin(int pin);
    void setName(char* n);
    
private:
    char* name;
    int cnp;
    int pin;
    
};


#endif /* Atm_hpp */
