//
//  PriorityQ.hpp
//  SDA
//
//  Created by Timofte Ciprian Andrei on 22/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef PriorityQ_hpp
#define PriorityQ_hpp

#include <stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class PriorityQ {
    
private:
    
    vector<int> queue;
    
public:
    
    PriorityQ(){};
    ~PriorityQ();
    
    int size();
    int get();
    void print();
    void put(int n);
    bool empty();
    
};

#endif /* PriorityQ_hpp */
