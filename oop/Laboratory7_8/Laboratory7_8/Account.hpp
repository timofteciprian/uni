//
//  Account.hpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
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
    
    Account(const string &name, const string &idCard, unsigned int pin);
    
    Account();
    
    virtual ~Account();
    
    const string &getName() const;
    
    const string &getIdCard() const;
    
    unsigned int getPin() const;
    
    void setName(const string &name);
    
    void setIdCard(const string &idCard);
    
    void setPin(unsigned int pin);
    
private:
    string name;
    string idCard;
    unsigned int pin;

};

#endif /* Account_hpp */
