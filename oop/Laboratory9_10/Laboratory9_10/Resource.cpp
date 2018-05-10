//
//  Resource.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Resource.hpp"
#include <iostream>
//#include <string.h>
#include <string>

using namespace std;

Resource::Resource(){
    name = {};
    dateEntry = 0;
    value = 0;
    
}

/*Resource* Resource::clone(){
 Resource* newResource;
 newResource = new Resource();
 newResource->setName(this->name);
 newResource->setDateEntry(this->dateEntry);
 newResource->setValue(this->value);
 return newResource;
 }*/
Resource::Resource(Resource &m){
    name = m.name ;
    dateEntry = m.dateEntry;
    value = m.value;
}

Resource::~Resource(){
}

string Resource::getName(){
    return name;
}
void Resource::setName(string n){
    name = n;
}

unsigned int Resource::getDateEntry(){
    return dateEntry;
}
void Resource::setDateEntry(unsigned int dateE){
    dateEntry = dateE;
}

int Resource::getValue(){
    return value;
}
void Resource::setValue(int val){
    value = val;
}
istream& operator>>( istream& input, Resource *r ) {
    r->read(input);
    return input ;
}

void Resource::read(istream& input){
    input >> name;
    input >> dateEntry;
    input >> value;
}

ostream& operator<<( ostream& output, Resource* r ){
    r->write(output);
    return output;
}

void Resource::write(ostream &output){
    output << "Name: " << name << endl;
    output << "Date: " << dateEntry << endl;
    output << "Value: " << value << endl;
}

Resource& Resource::operator=(const Resource &r) {
    if (this != &r){
        name = r.name;
        dateEntry = r.dateEntry;
        value = r.value;
    }
    return *this;
}


////istream& operator>>(istream &is, Flower &f){
//    char* s = new char[100];
//    is >> s;
//    char *next_token;
//    char* aux = strtok_s(s, ";", &next_token);
//    f.name = new char[strlen(aux) + 1];
//    strcpy_s(f.name, strlen(aux) + 1, aux);
//    aux = strtok_s(NULL, ";", &next_token);
//    f.price = atoi(aux);
//    return is;
//}
//ostream& operator<<(ostream &os, Resource &r){
//    os << "Name " << r.name << endl;
//    os << " Date: " << r.dateEntry << endl;
//    os << " Value: " << r.value << endl;
//    return os;
//}


//ostream& operator<<( ostream& output, Resource &r ) {
//    return  output << "Name: " <<  r.name << endl << " Date: " << r.dateEntry<< endl << " Value: " << r.value << endl; }

