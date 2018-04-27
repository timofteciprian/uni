//
//  Account.hpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    Account(unsigned int pin);
    
    Account(const string &name, const string &id, unsigned int pin);
    
    Account();
    
    virtual ~Account();
    
    const string &getName() const;
    
    const string &getId() const;
    
    unsigned int getPin() const;
    
    void setName(const string &name);
    
    void setId(const string &id);
    
    void setPin(unsigned int pin);
    
    friend ostream &operator<<(ostream &os, const Account &Account);
    
private:
    string name;
    string id;
    unsigned int pin;
    
    
};




#endif /* Account_hpp */
