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
 decr: adds an Expence object
 in: ex
 out:-
 */
void Repository::addExpense(Expense ex){
    this->costs = this->costs + ex;
}
/*
 decr: returns the Expense list
 in:
 out: costs
 */
DynamicVector<Expense> &Repository::getAll(){
    return this->costs;
}
/*
 decr: Eliminate cost of apartment
 in: expense
 out:
 */
void Repository::elimCostsOfApartment(Expense ex){
    this->costs = this->costs - ex;
}
/*
 decr: Replace sum for a expense
 in: index(expense), new sum
 out:
 */
void Repository::replaceSumExpense(int index, unsigned int newSum){
    this->costs[index].setSum(newSum);
}
/*
 decr: delete all explense
 in:
 out:
 */
void Repository::clearAll(){
    this->costs.clear();
}
/*
 decr: Change two expenses between them
 in:
 out:
 */
void Repository::changePosition(int a, int b){
    swap(this->costs[a],this->costs[b]);
}
/*
 decr: Operator addition
 in:
 out:
 */
DynamicVector <Expense> operator + (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}
/*
 decr: Operator addition
 in:
 out:
 */
DynamicVector <Expense> operator + (const Expense &b, const DynamicVector <Expense> &a) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}
/*
 decr: Operator minus
 in:
 out:
 */
DynamicVector <Expense> operator - (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.remove(b);
    //ret.erase(remove(ret.begin(), ret.end(), b), ret.end());
    return ret;
}
