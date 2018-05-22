
//
//  heap.hpp
//  SDA
//
//  Created by Timofte Ciprian Andrei on 22/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <iostream>
#include<vector>

using namespace std;

class Heap {
    
private:
    
    vector<int> heap;
    
public:
    
    Heap() {};
    ~Heap();
    
    
    int size();
    void push(int nod);
    int fst(int i);
    void upH();
    int parent(int i);
    void downH();
    int pop();
    void print();
    void swap(int n1, int n2);
    int top();
    
};


#endif /* heap_hpp */
