//
//  Controller.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Controller.hpp"
//empty constructor
Controller::Controller() {}

//returneaza suma de bani disponibila in ATM
unsigned int Controller::getSuma() const {
    return suma;
}

//seteaza suma de bani din ATM
void Controller::setSuma(unsigned int suma) {
    Controller::suma = suma;
}

//returneaza lista de Accounturi
vector<Account> Controller::getClienti() {
    return this->clienti.getAll();
}

//constructor
Controller::Controller(const RepoT<Account> &clienti) : clienti(clienti) {}

//adauga Account in lista de Accounturi
void Controller::addAccount(string nume, string cnp, unsigned int pin) {
    this->clienti.addAccount(Account(nume, cnp, pin));
    
}
