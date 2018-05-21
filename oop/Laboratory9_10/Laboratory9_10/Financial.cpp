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

Financial::Financial():Resource(){
    this->coin = {};
}

Financial::Financial(Financial &f):Resource(f){
    this->coin = f.coin;
}
Financial::~Financial(){}

string Financial::getCoin(){
    return this->coin;
}
void Financial::setCoin(string coin){
    this->coin = coin;
}

void Financial::read(istream &input){
    string name;
    unsigned int dateEntry;
    int value;
    input >> name;
    setName(name);
    input >>dateEntry;
    setDateEntry(dateEntry);
    input >>value;
    setValue(value);
    input >> coin;
}

void Financial::write(ostream &output){
    output << "Name: " << getName() << endl;
    output << "Date: "<< getDateEntry() << endl;
    output << "Value: " << getValue() <<endl;
    output << "Coin: " << coin << endl;
    
}

Resource* Financial::clone(){
    Financial* newFinancial = new Financial();
    newFinancial->setName(name);
    newFinancial->setDateEntry(dateEntry);
    newFinancial->setValue(value);
    newFinancial->coin = coin;
    return newFinancial;
}

string Financial::toString(){
    stringstream ss;
    ss<<"Resource financial: "<< this->name <<", "<< this->dateEntry <<", "<< this->value <<", "<< this->coin<<endl;
    return ss.str();
}
