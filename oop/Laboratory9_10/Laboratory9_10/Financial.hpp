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
    //Financial(string name, unsigned int dateEntry, int value, string coin);
    Financial(Financial & f);
    ~Financial();
    
    Resource* clone()override;
    
    string getCoin();
    void setCoin(string coin);
    
    virtual void read(istream& input)override;
    virtual void write(ostream& output)override;
    
    
    //friend istream& operator>> ( istream& input, Financial* f );
    //friend ostream& operator <<(ostream& output,const Financial *f);
    
    //
    //    virtual istream& read(istream& input ) override {
    //        Resource::read(input);
    //        string coin;
    //        input >> coin;
    //        this->coin = coin;
    //        return input ;
    //    }
    
    //    //    virtual ostream& write( ostream& output ) const override
    //    //    { return Resource::write(output) << " Coin: " << coin << endl ; }
    //    //
    //
    //    bool operator==(const Financial &f) const{
    //        return this->coin == f.coin;
    //    }
    //
    //    Financial& operator=(const Financial &f);
    //
    //
    string toString()override;
};



#endif /* Financial_hpp */
