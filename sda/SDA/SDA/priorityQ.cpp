//
//  PriorityQ.cpp
//  SDA
//
//  Created by Timofte Ciprian Andrei on 22/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "PriorityQ.hpp"

// destructor
PriorityQ::~PriorityQ(){
    this->queue.clear();
}

// marimea heap-ului
int PriorityQ::size(){
    return this->queue.size();
}

// afisare
void PriorityQ::print(){
    if (this->size()==0)
    {
        cout << "Priority queue is empty!"<<endl;
    }
    cout << "Queue = ";
    for (int i = 0; i < this->size(); i++)
        cout << this->queue[i] << ",";
    cout << endl;
}

// ia si sterge prima valoare
int PriorityQ::get(){
    int val = this->queue[0];
    this->queue.erase(this->queue.begin());
    return val;
}

// adauga
void PriorityQ::put(int n){
    this->queue.push_back(0);
    int i = this->size() - 1;
    for (; i > 0; i--)
        if (n < this->queue[i - 1])
            break;
        else this->queue[i] = this->queue[i - 1];
    this->queue[i] = n;
    
}

bool PriorityQ::empty() {
    return this->size() == 0 ? true:false;
}
