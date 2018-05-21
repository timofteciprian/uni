//
//  Resource.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Resource.hpp"
#include <iostream>
#include <string>

using namespace std;

Resource::Resource(){
    name = {};
    dateEntry = 0;
    value = 0;
    
}

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
