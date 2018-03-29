//
//  Controller.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include  "Controller.hpp"


Controller::Controller(Repository &repo): repo(repo){
}


void Controller::addExpense(unsigned int no, unsigned int sum, Expense::ExpenseType t){
    Expense ex (no,sum,t);
    this->repo.addExpense(ex);
}

DynamicVector<Expense> &Controller::getAll(){
    return this->repo.getAll();
}


void Controller::elimCostsOfApartment(unsigned int no){
    this->repo.elimCostsOfApartment(no);
}


 //void elimiCostsMoreApartment()

