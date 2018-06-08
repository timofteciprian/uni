//
//  RepoFile.hpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef RepoFile_hpp
#define RepoFile_hpp

#include <stdio.h>
#include "Repo.hpp"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

template <class T>
class RepoFile : public  Repo<T> {
private:
    ifstream  in;
    ofstream of;
    string fileName;
public:
    //Constructor fara param
    RepoFile() :Repo<T>() {};
    
    //Constructor cu paramentrii,desc. f
    RepoFile(const string fileName) {
        this->fileName = fileName;
        in.open(fileName);
        if (!in) //verifica daca este ceva in fisier
            cerr << "Error in opening the file" << endl;
    }
    
    //Destructor,inc. f
    ~RepoFile() {
        in.close();
        of.close();
    }
    
    // Seteaza numele fisierului
    void setFile(const string fileName) {
        this->fileName = fileName;
        in.open(fileName);
        if (!in)
            cerr << "Error in opening the file" << endl;
    }
    
    //Operatorul de atribuire
    //In,out: Referinta la repofile
    const RepoFile<T>& operator=(const RepoFile<T>& r) {
        in = r.in;
        this->fileName = r.fileName;
        return *this;
    }
    
    //Adauga elemente din fisier, (ia datele din fisier)
    void addElement() {
        T el;
        while (in >> el) {
            Repo<T>::addElem(el);
        }
    }
    
    //setter pentru numar
    void setNumar(int numar, int pos) {
        this->elem[pos].setNumar(numar);
    }
    
    //Returneaza toate elementele din fisier, copia lui getAll() din repo
    vector<T> getAll() {
        return Repo<T>::getAll();
    }
    
    //suprascrie datele din fisier
    void scriere() {
        of.open(this->fileName);
        for (unsigned int i = 0; i < this->elem.size(); i++)
            of << this->elem[i];
    }
};

#endif /* RepoFile_hpp */
