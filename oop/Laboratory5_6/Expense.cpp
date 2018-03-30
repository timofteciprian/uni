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

/** Default constructor */

Expense::Expense(){
    this->noApartment = 0;
    this->sum = 0;
}

/** Default constructor with param  */

Expense::Expense(unsigned int no, unsigned int s ,Expense::ExpenseType t){
    this->noApartment = no;
    this->sum = s;
    this->typee = t;
}

/* Copy constructor
  param other Object to copy from
 */

Expense::Expense(const Expense &e){
    this->noApartment = e.noApartment;
    this->sum = e.sum;
    this->typee = e.typee;
}

/** Default destructor */

Expense::~Expense(){
    this->noApartment = 0;
    this->sum = 0;    
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




