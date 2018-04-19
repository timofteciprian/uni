//
//  Repository.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Repository.hpp"

Repository::Repository(const vector<Account> &accounts) : accounts(accounts) {this->accounts={};}

Repository::~Repository() {
    
}

const vector<Account> &Repository::getAccounts() const {
    return accounts;
}

void Repository::update(unsigned int pos, Account c) {
    Repository::accounts[pos]=c;
}

void Repository::deleteElem(unsigned int pos) {
    Repository::accounts.erase(Repository::accounts.begin()+pos);
}

void Repository::addElem(Account c) {
    Repository::accounts.push_back(c);
}

Repository::Repository() {this->accounts={};}

void Repository::populate() {
    Repository::addElem(Account("Alin","123456789",1234));
    Repository::addElem(Account("Marcel","152654423",1345));
    Repository::addElem(Account("Maria","4564555434",7855));
    Repository::addElem(Account("Dumitru","6367376547",7467));
    
}
