//
//  Financial.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Financial_hpp
#define Financial_hpp

#include"Resource.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Financial : public Resource {
private:
    string coin;
    
public:
    Financial();
    Financial(Financial & f);
    ~Financial();
    
    Resource* clone()override;
    
    string getCoin();
    void setCoin(string coin);
    
    virtual void read(istream& input)override;
    virtual void write(ostream& output)override;
    
    string toString()override;
};



#endif /* Financial_hpp */
