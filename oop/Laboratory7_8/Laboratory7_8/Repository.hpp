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
    vector<T> getAccounts();
    
    void addElem(T element);
    void deleteElem(unsigned int index);
    void update(unsigned int index, T element);
    
private:
    vector<T> accounts;
};


template <class T>
vector<T> Repository<T>::getAccounts() {
    return this->accounts;
}

template <class T>
void Repository<T>::update(unsigned int index, T c) {
    this->accounts[index]=c;
}

template <class T>
void Repository<T>::deleteElem(unsigned int index) {
    this->accounts.erase(this->accounts.begin()+index);
}

template <class T>
void Repository<T>::addElem(T c) {
    this->accounts.push_back(c);
}



#endif /* Repository_hpp */
