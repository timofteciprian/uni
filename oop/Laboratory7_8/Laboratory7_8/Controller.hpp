//
//  Controller.hpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>

#include "RepoT.hpp"
#include "Account.hpp"

class Controller{
public:
    Controller();
    
    Controller(const RepoT<Account> &clienti);
    
    unsigned int getSuma() const;
    
    void setSuma(unsigned int suma);
    
    vector<Account> getClienti();
    
    void addAccount(string, string, unsigned int);
    
private:
    RepoT<Account> clienti;
    unsigned int suma=0;
    
};


#endif /* Controller_hpp */
