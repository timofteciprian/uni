//
//  Resource.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Resource_hpp
#define Resource_hpp

#include <stdio.h>
#include<iostream>
#include <string>

using namespace std;

class Resource{
private:
    char* name;
    unsigned int dateEntry;
    int value;

public:
    
    Resource();
    Resource(char* name, unsigned int dateEntry, int value);
    //Resource(Resource &m);
    ~Resource();
    
    char* getName();
    void setName(char* name);
    
    unsigned int getDateEntry();
    void setDateEntry(unsigned int dateEntry);
    
    int getValue();
    void setValue(int value);
    
    bool operator==(const Resource &m) const{
        return this->name == m.name and this->dateEntry == m.dateEntry and this->value == m.value;
    }

    friend istream& operator>> (istream &input, Resource &m);
    
    Resource& operator=(const Resource &r);
    
  
//    friend ostream &operator << (ostream &output, Resource &m);
//    
    //friend istream &operator >> (istream &input, Resource &m);
    
    
};

#endif /* Resource_hpp */
