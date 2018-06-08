//
//  Repo.hpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repo_hpp
#define Repo_hpp

#include <stdio.h>
#include <vector>
using namespace std;

template <class T>
class Repo {
protected:
    vector <T> elem;
    int CAP = 30;
public:
    //constr fara param
    Repo() {}
    //destructor
    ~Repo() {
        this->elem.~vector();
    }

    void addElem(T el) {
        this->elem.push_back(el);
    }
    
    vector<T> getAll() {
        return this->elem;
    }
    
    void setNumar(int numar, int pos) {
        this->elem[pos].setNumar(numar);
    }
};
#endif /* Repo_hpp */
