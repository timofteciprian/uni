//
//  Material.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 05/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Material.hpp"
#include <iostream>
#include <string>

using namespace std;

Material::Material():Resource(){
    lifeTime = 0;
    no = 0;
}

Material::Material(Material &m):Resource(m){
    lifeTime = m.lifeTime;
    no = m.no;
}

Material::~Material(){
}

int Material::getLifeTime(){
    return lifeTime;
}
void Material::setLifeTime(int lifeT){
    lifeTime = lifeT;
}

int Material::getNo(){
    return no;
}
void Material::setNo(int n){
    no = n;
}

void Material::read(istream &input){
    string name;
    unsigned int dateEntry;
    int value;
    input >> name;
    setName(name);
    input >>dateEntry;
    setDateEntry(dateEntry);
    input >>value;
    setValue(value);
    input >> lifeTime;
    input >> no;
}

void Material::write(ostream &output){
    output << "Name: " << getName() << endl;
    output << "Date: "<< getDateEntry() << endl;
    output << "Value: " << getValue() <<endl;
    output << "Life Time: " << lifeTime << endl;
    output << "No: "<<  no << endl ;
}

Material& Material::operator=(const Material &m) {
    if (this != &m){
        Resource::operator=(m);
        lifeTime = m.lifeTime;
        no = m.no;
    }
    return *this;
}

Resource* Material::clone(){
    Material* newMaterial = new Material();
    newMaterial->setName(name);
    newMaterial->setDateEntry(dateEntry);
    newMaterial->setValue(value);
    newMaterial->lifeTime = lifeTime;
    newMaterial->no = no;
    return newMaterial;
}

string Material::toString(){
    stringstream ss;
    ss<<"Resource material: "<< this->name <<", "<< this->dateEntry <<", "<< this->value <<", "<< this->lifeTime <<", "<< this->no<<endl;
    return ss.str();
}

