//
//  Atm.cpp
//  Laboratory_7_8
//
//  Created by Timofte Ciprian Andrei on 03/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//
#include<string>
#include "Atm.hpp"

Atm::Atm(){
    this->name = NULL;
    this->cnp = 0;
    this->pin = 0;
}

Atm::Atm(char* n, int p, int c){
    this->cnp = c;
    this->pin = p;
    this->name = new char [strlen(n)+1];
    strcpy(this->name, n);
    
}

Atm::Atm(Atm & a){
    this->cnp = a.cnp;
    this->pin = a.pin;
    this->name = new char [strlen(a.name)+1];
    strcpy(this->name, a.name);
}
Atm::~Atm(){
    delete[] this->name;
}

char* Atm::getName(){
    return this->name;
}


int Atm::getCnp(){
    return this->cnp;
}

int Atm::getPin(){
    return this->pin;
}

void Atm::setCnp(int c){
    this->cnp = c;
}

void Atm::setPin(int p){
    this->pin = p;
}

void Atm::setName(char* n){
    this->name = new char [strlen(n)+1];
    strcpy(this->name, n);
}



