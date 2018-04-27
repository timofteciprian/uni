//
//  RepoT.hpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef RepoT_hpp
#define RepoT_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Account.hpp"

using namespace std;

template<class T> class RepoT{
public:
    RepoT();
    virtual ~RepoT();
    vector<T> getAll();
    void addAccount(T);
    int getSize();
    
private:
    vector<T> conturi;
};

template class RepoT<Account>;

//contructor
template<class T>
RepoT<T>::RepoT() {
    this->conturi={};
}

//empty contructor
template<class T>
RepoT<T>::~RepoT() {
    
}
//adauga cont in vector
template<class T>
void RepoT<T>::addAccount(T c) {
    
    this->conturi.push_back(c);
    
}
//returneaza lungimea vectorului de conturi
template<class T>
int RepoT<T>::getSize() {
    int size;
    size = this->conturi.size();
    return size;
}

//returneaza lista de conturi
template <class T> vector<T> RepoT<T>::getAll() {
    return this->conturi;
}





#endif /* RepoT_hpp */
