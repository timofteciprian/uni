//
//  Client.cpp
//  Laboratory_7_8
//
//  Created by Timofte Ciprian Andrei on 03/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//
#include<string>
#include "Client.hpp"

Client::Client(){
    this->firstName = NULL;
    this->lastName = NULL;
    this->cnp = 0;
    this->pin = 0;
}

Client::Client(char* firstN, char* lastN, int p, int c){
    this->cnp = c;
    this->pin = p;
    this->firstName = new char [strlen(firstN)+1];
    strcpy(this->firstName, firstN);
    this->lastName = new char [strlen(lastN)+1];
    strcpy(this->lastName, lastN);
    
}

Client::Client(Client & a){
    this->cnp = a.cnp;
    this->pin = a.pin;
    this->firstName = new char [strlen(a.firstName)+1];
    strcpy(this->firstName, a.firstName);
    this->lastName = new char [strlen(a.lastName)+1];
    strcpy(this->lastName, a.lastName);
}
Client::~Client(){
    delete[] this->firstName;
    this->firstName = NULL;
    delete[] this->lastName;
    this->lastName = NULL;
}

char* Client::getFirstName(){
    return this->firstName;
}
void Client::setFirstName(char* n){
    this->firstName = new char [strlen(n)+1];
    strcpy(this->firstName, n);
}

char* Client::getLastName(){
    return this->lastName;
}
void Client::setLastName(char* n){
    this->lastName = new char [strlen(n)+1];
    strcpy(this->lastName, n);
}

double Client::getCnp(){
    return this->cnp;
}
void Client::setCnp(int c){
    this->cnp = c;
}

int Client::getPin(){
    return this->pin;
}
void Client::setPin(int p){
    this->pin = p;
}





