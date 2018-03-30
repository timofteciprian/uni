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


void Controller::elimCostsOfApartment(unsigned int no, unsigned int sum, Expense::ExpenseType typpe){
    Expense ex (no,sum, typpe);
    this->repo.elimCostsOfApartment(ex);
}

void Controller::elimCostsMoreApartments(int count, int* array){
    int no,sum;
    Expense::ExpenseType typpe;
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<count; i++){
        no = array[i];
        for(int i=0; i<all.size(); i++){
            Expense ex = all[i];
            if(ex.getNoApartment() == no){
                sum = ex.getSum();
                typpe = ex.getExpenseType();
            this->repo.elimCostsOfApartment(Expense(no,sum,typpe));
            }
        }
    }
}

