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
    this->name = NULL;
    this->dateEntry = 0;
    this->value = 0;
 
}

Resource::Resource(char* name, unsigned int dateEntry, int value){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    //this->name = name;
    this->dateEntry = dateEntry;
    this->value = value;
 
}

//Resource::Resource(Resource &m){
//    //this->name = new char[strlen(m.name)+1];
//    strcpy(this->name, m.name);
//    //this->name = m.name;
//    this->dateEntry = m.dateEntry;
//    this->value = m.value;
//}

Resource::~Resource(){
}

char* Resource::getName(){
    return this->name;
}
void Resource::setName(char* name){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    //this->name = name;
}

unsigned int Resource::getDateEntry(){
    return this->dateEntry;
}
void Resource::setDateEntry(unsigned int dateEntry){
    this->dateEntry = dateEntry;
}

int Resource::getValue(){
    return this->value;
}
void Resource::setValue(int value){
    this->value = value;
}
istream& operator>> (istream &input, Resource &m) {
    char* name = new char[20];
    input >> name;
    m.name = name;
    input >> m.dateEntry;
    input >> m.value;
    
    return input/*input >> m.name >> m.dateEntry >> m.value >> m.lifeTime >> m.no*/;
}


Resource& Resource::operator=(const Resource &r) {
    if (this != &r){
        this->name = new char[100];
        strcpy(this->name, r.name);
        this->dateEntry = r.dateEntry;
        this->value = r.value;
    }
    return *this;
}
//
//ostream& operator<< (ostream &output, Resource &m) {
//    output << "Name: " << m.name << endl;
//    output << "Date: " << m.dateEntry << endl;
//    output << "Value: " << m.value << endl;
//    output << "Life Time: " << m.lifeTime << endl;
//    output << "No: " << m.no << endl;
//    return output;
//}
//






