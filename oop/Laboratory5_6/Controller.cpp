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
void Controller::replaceSumExpense(unsigned int no, unsigned int newSum,unsigned int typee){
    int index;
    index = findExpenseByNoAndSum(no, typee);
    this->repo.replaceSumExpense(index, newSum);
}

int Controller::findExpenseByNoAndSum(unsigned int no, unsigned int typee){
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(no == ex.getNoApartment() and typee == ex.getExpenseType())
            return i;
    }
    return -1;
}

int Controller::findExpenseByNo(unsigned int no){
    DynamicVector<Expense> all = this->repo.getAll();
    for( int i=0; i<all.size(); i++){
        Expense ex =  all[i];
        if(no == ex.getNoApartment())
            return i;
    }
    return -1;
}

int Controller::sumAllTypeExpense(int typee){
    int sum = 0;
    DynamicVector<Expense> all = this->repo.getAll();
    for( int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(ex.getExpenseType() == typee)
            sum = sum + ex.getSum();
    }
    return sum;
}

int Controller::sumHighOfApartment(unsigned int no){
    int sum = 0, index = -1;
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(no == ex.getNoApartment() and sum < ex.getSum()){
            sum = ex.getSum();
            index = i;
        }
    }
    return index;
}

void Controller::orderDescendingForType(int typee){
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size()-1; i++){
        for(int j=i+1; j<all.size(); j++){
            Expense ex1 = all[i];
            Expense ex2 = all[j];
            if(typee == ex1.getExpenseType() and typee == ex2.getExpenseType() and ex1.getSum()<ex2.getSum())
                this->repo.changePosition(i, j);
        }
    }
}

void Controller::sortByType(){
    Expense::ExpenseType typee;
    DynamicVector<Expense> all = this->repo.getAll();
    this->repo.clearAll();
    for(int i=0; i<5; i++)
        for(int j=0; j<all.size(); j++){
            Expense ex = all[j];
            typee = ex.getExpenseType();
            if(typee == i)
                this->repo.addExpense(ex);
    }
}

void Controller::filterByType(int typee){
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(typee != ex.getExpenseType())
            this->repo.elimCostsOfApartment(ex);
    }
}

void Controller::undo(DynamicVector<Expense> all){
    this->repo.clearAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        this->repo.addExpense(ex);
    }
}

