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

//Financial::Financial(string name, unsigned int dateEntry, int value, string coin):Resource(name,dateEntry,value){
//    this->coin = coin;
//}

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
//istream& operator>>( istream& input, Financial *f ) {
//    input >> static_cast<Resource*>(f);
//    input >> f->coin;
//    return input ;
//}
//
//ostream& operator <<(ostream& output,const Financial *f){
//    output << static_cast<const Resource*>(f);
//    output << "Coin: "<<  f->coin << endl ;
//    return output;
//}

void Financial::read(istream &input){
    //input >> static_cast<Resource*>();
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

//ostream& operator <<(ostream& output,const Material *m){
//    m->write(output);
//    return output;
//}

void Financial::write(ostream &output){
    //output << static_cast<const Resource*>(m);
    output << "Name: " << getName() << endl;
    output << "Date: "<< getDateEntry() << endl;
    output << "Value: " << getValue() <<endl;
    output << "Coin: " << coin << endl;
    
}
//Financial& Financial::operator=(const Financial &f) {
//    if (this != &f){
//        Resource::operator=(f);
//        this->coin = f.coin;
//    }
//    return *this;
//}
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
