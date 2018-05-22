//
//  main.cpp
//  SDA
//
//  Created by Timofte Ciprian Andrei on 22/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include<iostream>
#include "PriorityQ.hpp"
#include "Heap.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Priority Queue : " << endl;
    PriorityQ * q = new PriorityQ();
    q->print();
    q->put(17);
    q->print();
    q->put(23);
    q->print();
    q->put(9);
    q->print();
    
    cout << "Primul element : " << q->get() << endl;
    q->print();
    
    
    cout << "Heap-ul : " << endl;
    Heap * h = new Heap();
    h->push(99);
    h->print();
    h->push(10);
    h->print();
    h->push(2);
    h->print();
    
    cout << "Radacina heap-ului : "<<h->top() << endl;
    h->pop();
    h->print();
    h->pop();
    h->print();
    
    return 0;
}
