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

class Resource {
    
protected:
    string name;
    unsigned int dateEntry;
    int value;
    
public:
    
    Resource();
    //Resource(string name, unsigned int dateEntry, int value);
    Resource(Resource &m);
    virtual~Resource();
    
    virtual Resource* clone()=0;
    
    string getName();
    void setName(string name);
    
    unsigned int getDateEntry();
    void setDateEntry(unsigned int dateEntry);
    
    int getValue();
    void setValue(int value);
    
    virtual Resource& operator=(const Resource &r);
    friend istream& operator>>( istream& input, Resource *r );
    friend ostream& operator<<( ostream& output, Resource *r );
    
    virtual void read(istream& input);
    virtual void write(ostream& output);
    
    bool operator==(const Resource &r) const{
        return name == r.name and dateEntry == r.dateEntry and value == r.value;
    }
    virtual string toString()=0;
};


#endif /* Resource_hpp */
