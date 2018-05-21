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
#include <sstream>
#include "Resource.hpp"

using namespace std;

class Material : public Resource {
private:
    
    int lifeTime;
    int no;
    
public:
    
    Material();
    Material(Material &m);
    ~Material();
    
    Resource* clone()override;
    
    int getLifeTime();
    void setLifeTime(int lifeTime);
    
    int getNo();
    void setNo(int no);
    
    virtual void read(istream& input)override;
    virtual void write(ostream& output)override;
 
    Material& operator=(const Material &m);
    string toString()override;
    
};


#endif /* Material_hpp */
