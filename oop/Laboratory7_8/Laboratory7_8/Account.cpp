//
//  Account.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Account.hpp"

Account::Account(unsigned int pin) {
    this->pin = pin;
}

Account::Account() {
    this->pin = 0;
}

Account::~Account() {
    
}

const string Account::getName() const {
    return this->name;
}

const string Account::getIdCard() const {
    return this->idCard;
}

unsigned int Account::getPin() const {
    return this->pin;
}

void Account::setName(const string &name) {
    this->name = name;
}

void Account::setIdCard(const string &idCard) {
    this->idCard = idCard;
}

void Account::setPin(unsigned int pin) {
    this->pin = pin;
}

Account::Account(const string &name, const string &idCard, unsigned int pin) {
    this->name = name;
    this->idCard = idCard;
    this->pin = pin;
}
