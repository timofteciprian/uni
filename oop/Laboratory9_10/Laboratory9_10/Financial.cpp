//
//  Financial.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Financial.hpp"
#include <iostream>
#include <string>

Financial::Financial(){
    this->name = {};
    this->dateEntry = 0;
    this->value = 0;
    this->coin = {};
}

Financial::Financial(string name, unsigned int dateEntry, int value, string coin){
    this->name = name;
    this->dateEntry = dateEntry;
    this->value = value;
    this->coin = coin;
}

Financial::Financial(Financial &f){
    this->name = f.name;
    this->dateEntry = f.dateEntry;
    this->value = f.value;
    this->coin = f.coin;
}
Financial::~Financial(){}

string Financial::getName(){
    return this->name;
}
void Financial::setName(string name){
    this->name = name;
}

unsigned int Financial::getDateEntry(){
    return this->dateEntry;
}
void Financial::setDateEntry(unsigned int dateEntry){
    this->dateEntry = dateEntry;
}

int Financial::getValue(){
    return this->value;
}
void Financial::setValue(int value){
    this->value = value;
}

string Financial::getCoin(){
    return this->coin;
}
void Financial::setCoin(string coin){
    this->coin = coin;
}

