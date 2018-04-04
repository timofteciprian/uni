//
//  Client.hpp
//  Laboratory_7_8
//
//  Created by Timofte Ciprian Andrei on 03/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>

class Client{
public:
    Client();
    Client(char* firstN, char* lastN, int c, int p);
    Client(Client & a);
    ~Client();
    
    char* getFirstName();
    void setFirstName(char* firstN);
    
    char* getLastName();
    void setLastName(char* lastN);

    double getCnp();
    void setCnp(int cnp);
    
    int getPin();
    void setPin(int pin);
    
    
private:
    char* firstName;
    char* lastName;
    double cnp;
    int pin;
    
};


#endif /* Client_hpp */
