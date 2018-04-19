//
//  Account.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Account.hpp"

Account::Account(unsigned int pin) : pin(pin) {pin=0;}

Account::~Account() {
    
}

const string &Account::getName() const {
    return name;
}

const string &Account::getIdCard() const {
    return idCard;
}

unsigned int Account::getPin() const {
    return pin;
}

void Account::setName(const string &name) {
    Account::name = name;
}

void Account::setIdCard(const string &idCard) {
    Account::idCard = idCard;
}

void Account::setPin(unsigned int pin) {
    Account::pin = pin;
}

Account::Account(const string &name, const string &idCard, unsigned int pin) : name(name), idCard(idCard), pin(pin) {}

Account::Account() {
    Account::pin = 0;
}
