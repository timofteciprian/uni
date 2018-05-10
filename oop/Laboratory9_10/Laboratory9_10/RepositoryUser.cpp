//
//  RepositoryUser.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "RepositoryUser.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

RepositoryUser::RepositoryUser(){
    users = new User[10];
    this->size = 0;
    
}
RepositoryUser::RepositoryUser(string fileName){
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            User user;
            fin >> user ;
            add(user);
            //writeToFile("write.txt");
        }
        fin.close();
    }
    else
        cout << "No";
}

RepositoryUser::~RepositoryUser(){}

void RepositoryUser::add(User user){
    if(size == 0){
        users = new User[100];
    }
    users[size] = user;
    size++;
}

User* RepositoryUser::getAll(){
    return users;
}

int RepositoryUser::getSize(){
    return size;
}

RepositoryUser& RepositoryUser::operator=(const RepositoryUser &r) {
    if (this != &r){
        for(int i=0; i<size; i++){
            users[i] = r.users[i];
        }
    }
    return *this;
}
