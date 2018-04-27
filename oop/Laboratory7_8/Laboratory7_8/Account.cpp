//
//  Account.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Account.hpp"

Account::Account(unsigned int pin) : pin(pin) {pin=0;}

Account::~Account() {
    
}

//returneaza Namele
const string &Account::getName() const {
    return name;
}

//returneaza id ul
const string &Account::getId() const {
    return id;
}

//returneaza pin ul
unsigned int Account::getPin() const {
    return pin;
}

//seteaza Namele
void Account::setName(const string &name) {
    Account::name = name;
}

//seteaza id ul
void Account::setId(const string &id) {
    Account::id = id;
}

//seteaza pin ul
void Account::setPin(unsigned int pin) {
    Account::pin = pin;
}

//constructor cu parametrii
Account::Account(const string &name, const string &id, unsigned int pin) : name(name), id(id), pin(pin) {}


//constructor default
Account::Account() {
    Account::pin=0;
}

//operator
ostream &operator<<(ostream &os, const Account &Account) {
    os << Account.name << " " << Account.id << " " << Account.pin;
    return os;
}
