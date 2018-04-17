//
//  Repository.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Repository.hpp"
#include <iostream>
/*
 decr: adauga un obiect de tip Expence
 in: ex
 out:-
 */
void Repository::addExpense(Expense ex){
    this->costs = this->costs + ex;
}
/*
 decr: returneaza lista de tip Expence
 in:
 out: costs
 */
DynamicVector<Expense> &Repository::getAll(){
    return this->costs;
}

void Repository::elimCostsOfApartment(Expense ex){
    this->costs = this->costs - ex;
}

void Repository::replaceSumExpense(int index, unsigned int newSum){
    this->costs[index].setSum(newSum);
}

void Repository::clearAll(){
    this->costs.clear();
}

void Repository::changePosition(int a, int b){
    swap(this->costs[a],this->costs[b]);
}

DynamicVector <Expense> operator + (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}

DynamicVector <Expense> operator + (const Expense &b, const DynamicVector <Expense> &a) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}

DynamicVector <Expense> operator - (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.remove(b);
    //ret.erase(remove(ret.begin(), ret.end(), b), ret.end());
    return ret;
}
