//
//  Cusca.cpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Cusca.hpp"

Cusca::Cusca(){
    this->nume ={};
    this->zona ={};
    this->tip={};
}

Cusca::Cusca(bool f, bool c,string n, string z, string t){
    this->flamand = f;
    this->curatare = c;
    this->nume = n;
    this->zona = z;
    this->tip= t;
}

Cusca::Cusca(const Cusca &c){
    this->flamand = c.flamand;
    this->curatare = c.curatare;
    this->nume = c.nume;
    this->zona = c.zona;
    this->tip= c.tip;
}

Cusca::~Cusca(){}

void Cusca::setFlamand(bool f){
    this->flamand = f;
}
void Cusca::setCuratare(bool c){
    this->curatare = c;
}
void Cusca::setNume(string n){
    this->nume = n;
}
void Cusca::setZona(string z){
    this->zona = z;
}
void Cusca::setTip(string t){
    this->tip =t;
}
bool Cusca::getFlamand(){
    return this->flamand;
}
bool Cusca::getCuratare(){
    return this->curatare;
}
string Cusca::getNume(){
    return this->nume;
}
string Cusca::getZona(){
    return this->zona;
}
string Cusca::getTip(){
    return this->tip;
}

istream& operator>>( istream& input, Cusca &s ) {
    input >> s.flamand;
    input >> s.curatare;
    input >> s.nume;
    input >> s.zona;
    input >> s.tip;
    
    return input ;
}

ostream& operator<<( ostream& output, Cusca &s ){
    output << "Flamand: " << s.flamand << endl;
    output << "Cod: " << s.curatare << endl;
    output << "Descriere: " << s.nume << endl;
    output << "Cod: " << s.zona << endl;
    output << "Descriere: " << s.tip << endl;
    return output;
}
