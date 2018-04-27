//
//  Repository.hpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include "Account.hpp"
#include <vector>
#include <iostream>
#include <string>


template <class T>
class Repository {
public:
    
    void addSum(int s);
    void add(T element);
    void addElem(T element, int s);
    vector<T> getElements();
    vector<T> getElement(int index);
    int getSum();
    void deleteElem(unsigned int index);
    void update(unsigned int index, T element);
    
private:
    vector<T> elements;
    int sum;
};



template <class T>
void Repository<T>::addSum(int s) {
    this->sum = s;
}

template <class T>
void Repository<T>::add(T elem) {
    this->elements.push_back(elem);
}

template <class T>
void Repository<T>::addElem(T elem, int s) {
    this->elements.push_back(elem);
    this->sum = this->sum + s;
    
}

template <class T>
vector<T> Repository<T>::getElements() {
    return this->elements;
}

template <class T>
vector<T> Repository<T>::getElement(int index) {
    return this->elements[index];
}
template <class T>
int Repository<T>::getSum() {
    return this->sum;
}

template <class T>
void Repository<T>::update(unsigned int index, T c) {
    this->elements[index]=c;
}

template <class T>
void Repository<T>::deleteElem(unsigned int index) {
    this->elements.erase(this->elements.begin()+index);
}





#endif /* Repository_hpp */
