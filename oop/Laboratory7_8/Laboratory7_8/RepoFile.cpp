//
//  RepoFile.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "RepoFile.hpp"
#include <fstream>


RepoFile::RepoFile() {
}

RepoFile::RepoFile(char* fileName):RepoT<Account>(){
    string a, b;
    unsigned int c;
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            fin>>a;
            fin>>b;
            fin>>c;
            Account acc = Account(a,b,c);
            this->addAccount(acc);
        }
        fin.close();
    }
    else
        std::cout << "Fisier corupt";
}

RepoFile::~RepoFile() {
    
}

void RepoFile::loadFromFile(char* fileName){
    string a, b;
    unsigned int c;
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            fin>>a;
            fin>>b;
            fin>>c;
            Account acc = Account(a,b,c);
            this->addAccount(acc);
        }
        fin.close();
    }
    else
        std::cout << "Fisier corupt";
}


void RepoFile::writeToFile(char* fileName){
    ofstream fout;
    fout.open(fileName);
    vector<Account> all = this->getAll();
    for (int i = 0; i < this->getAll().size(); i++)
        fout <<all[i];
    fout.close();
}
