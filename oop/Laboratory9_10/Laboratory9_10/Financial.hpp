//
//  Financial.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Financial_hpp
#define Financial_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Financial{
public:
    Financial();
    Financial(string name, unsigned int dateEntry, int value, string coin);
    Financial(Financial & f);
    ~Financial();
    
    string getName();
    void setName(string name);
    
    unsigned int getDateEntry();
    void setDateEntry(unsigned int dateEntry);
    
    int getValue();
    void setValue(int value);
    
    string getCoin();
    void setCoin(string coin);
    
private:
    string name;
    unsigned int dateEntry;
    int value;
    string coin;
    
};



#endif /* Financial_hpp */
