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

Material::Material(){
    this->name = {};
    this->dateEntry = 0;
    this->value = 0;
    this->lifeTime = 0;
    this->no = 0;
}

Material::Material(string name, unsigned int dateEntry, int value, int lifeTime, int no){
    this->name = name;
    this->dateEntry = dateEntry;
    this->value = value;
    this->lifeTime = lifeTime;
    this->no = no;
}

Material::Material(Material &m){
    this->name = m.name;
    this->dateEntry = m.dateEntry;
    this->value = m.value;
    this->lifeTime = m.lifeTime;
    this->no = m.no;
}

Material::~Material(){
}

string Material::getName(){
    return this->name;
}
void Material::setName(string name){
    this->name = name;
}

unsigned int Material::getDateEntry(){
    return this->dateEntry;
}
void Material::setDateEntry(unsigned int dateEntry){
    this->dateEntry = dateEntry;
}

int Material::getValue(){
    return this->value;
}
void Material::setValue(int value){
    this->value = value;
}

int Material::getLifeTime(){
    return this->lifeTime;
}
void Material::setLifeTime(int lifeTime){
    this->lifeTime = lifeTime;
}

int Material::getNo(){
    return this->no;
}
void Material::setNo(int no){
    this->no = no;
}





