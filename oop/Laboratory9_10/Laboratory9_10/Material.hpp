//
//  Material.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include<iostream>
#include <string>

using namespace std;

class Material{
public:
    
    Material();
    Material(string name, unsigned int dateEntry, int value, int lifeTime, int no);
    Material(Material &m);
    ~Material();
    
    string getName();
    void setName(string name);
    
    unsigned int getDateEntry();
    void setDateEntry(unsigned int dateEntry);
    
    int getValue();
    void setValue(int value);
    
    int getLifeTime();
    void setLifeTime(int lifeTime);
    
    int getNo();
    void setNo(int no);
    
private:
    string name;
    unsigned int dateEntry;
    int value;
    int lifeTime;
    int no;
};

#endif /* Material_hpp */
