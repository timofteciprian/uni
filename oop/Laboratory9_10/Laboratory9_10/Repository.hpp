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
    
    //    int search(T elem);
    //    int getPoz(T elem);
    Resource* getAll();
    //    T getElement(int poz);
    int getSize();
    // Material* getMaterial();
    void writeToFile(const string fileName);
    //void loadFromFile(const char* fileName);
    //    inline T& operator [] (int pos) {
    //        return elements[pos];
    //    }
};


#endif /* Repository_hpp */
