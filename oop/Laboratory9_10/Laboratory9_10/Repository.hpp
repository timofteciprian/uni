//
//  Repository.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 06/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include "Resource.hpp"
#include "Material.hpp"
#include "Financial.hpp"

using namespace std;

class Repository{
private:
    int size;
    Resource** elements;
    string fileName;
    
public:
    Repository();
    Repository(string fileName);
    ~Repository();
    
    void readMaterial(string Material);
    void readFinancial(string Financial);
    void add(Resource* elem);
    Resource** getAll();
    int getSize();
    void loadFromFile(string fileName);
    void writeToFile(const string fileName);
    void modifyAMaterial(string name, unsigned int date, int value, int  lifeTime, int no,string newname, unsigned int newdate, int newvalue, int newlifetime, int newno );
    void modifyAFinancial(string name, unsigned int date, int value, string coin, string newname, unsigned int newdate, int newvalue, string newcoin);
    
};


#endif /* Repository_hpp */
