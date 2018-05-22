//
//  Heap.cpp
//  SDA
//
//  Created by Timofte Ciprian Andrei on 22/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "heap.hpp"
#include<iostream>
#include<vector>

using namespace std;


// destructor
Heap::~Heap(){
    this->heap.clear();
}

// marimea heap-ului
int Heap::size(){
    return this->heap.size();
}

// adauga
void Heap::push(int n){
    this->heap.push_back(n);
    this->upH();
}

int Heap::fst(int i)
{
    return(i << 1) + 1;
}


// rearanjeaza nodurile astfel incat sa respecte proprietatea de up Heap
void Heap::upH(){
    
    if (this->size() > 1)
    {
        int current , aux;
        current = this->heap.size() - 1;
        while (this->parent(current) > -1 and this->heap[current] > this->heap[this->parent(current)])
        {
            this->swap(current, this->parent(current));
            current = this->parent(current);
        }
    }
}

// returneaza parintele unui nod
int Heap::parent(int i){
    if (i < 1)
        return -1;
    if (i % 2 == 0)
        return i / 2 - 1;
    return i / 2;
}

// rearanjeaza nodurile astfel incat sa respecte proprietatea de down Heap
void Heap::downH(){
    int current = 0, maxf, aux;
    while (this->fst(current) < this->size())
    {
        maxf = this->fst(current);
        if (maxf + 1 < this->size())
            if (this->heap[maxf + 1] > this->heap[maxf])
                maxf++;
        if (this->heap[maxf] > this->heap[current])
        {
            this->swap(maxf, current);
            current = maxf;
        }
        else
            break;
    }
}

// sterge
int Heap::pop() {
    int max = this->top();
    this->swap(0, this->size() - 1);
    this->heap.pop_back();
    this->downH();
    return max;
}

// afisaza Heap-ul
void Heap::print(){
    if (this->size() == 0)
        cout << "Heap-ul este gol !"<<endl;
    else
    {
        cout << "Heap = ";
        for (int i = 0; i < this->size(); i++)
            cout << this->heap[i] << ",";
        cout << endl;
    }
}

// interschimba doua noduri
void Heap::swap(int n1, int n2){
    int aux = this->heap[n1];
    this->heap[n1] = this->heap[n2];
    this->heap[n2] = aux;
    
}

// returneaza radacina
int Heap::top(){
    return this->heap[0];
}



