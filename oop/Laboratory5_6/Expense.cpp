//
//  Expense.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Expense.hpp"
#include <iostream>
#include <string.h>

using namespace std;
//Dscr:
//In:
//Out:

//using namespace typeNs;

Expense::Expense(){
}

Expense::Expense(unsigned int no, unsigned int s ,Expense::ExpenseType t){
    cout<<"constructor with param";
    this->noApartment = no;
    this->sum = s;
    this->typee = t;
}

Expense::Expense(const Expense &e){
    cout<<"copy constructor";
    this->noApartment = e.noApartment;
    this->sum = e.sum;
    this->typee = e.typee;
}

Expense::~Expense(){
}


unsigned int Expense::getNoApartment(){
    return this -> noApartment;
}
void Expense::setNoApartment(unsigned int nr){
    this->noApartment = nr;
}

unsigned int Expense::getSum(){
    return this->sum;
}

void Expense::setSum(unsigned int s){
    this->sum = s;
}

Expense::ExpenseType Expense::getExpenseType(){
    return this->typee;
}

void Expense::setExpenseType(Expense::ExpenseType t) {
    this->typee = t;
}




