`//
//  Controller.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include  "Controller.hpp"


Controller::Controller(Repository &repo): repo(repo){
}
/*
 decr: Add expense
 in: no, sum, type
 out:
 */
void Controller::addExpense(unsigned int no, unsigned int sum, Expense::ExpenseType t){
    Expense ex (no,sum,t);
    this->repo.addExpense(ex);
}
/*
 decr: Get all expenses
 in:
 out: list
 */
DynamicVector<Expense> &Controller::getAll(){
    return this->repo.getAll();
}
/*
 decr: Eliminate cost of apartment
 in: no, sum, type
 out:
 */

void Controller::elimCostsOfApartment(unsigned int no, unsigned int sum, Expense::ExpenseType typpe){
    Expense ex (no,sum, typpe);
    this->repo.elimCostsOfApartment(ex);
}
/*
 decr: Eliminate costs more apartments
 in: list(apartments) count (length of the list)
 out:
 */
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
/*
 decr: Replace sum for expense
 in: no, type, new sum
 out:
 */
void Controller::replaceSumExpense(unsigned int no, unsigned int newSum,unsigned int typee){
    int index;
    index = findExpenseByNoAndType(no, typee);
    this->repo.replaceSumExpense(index, newSum);
}
/*
 decr: Find expense by no and type of expense
 in: no,  type
 out:
 */
int Controller::findExpenseByNoAndType(unsigned int no, unsigned int typee){
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(no == ex.getNoApartment() and typee == ex.getExpenseType())
            return i;
    }
    return -1;
}
/*
 decr: Find expense by no
 in: no
 out: index expense by list
 */
int Controller::findExpenseByNo(unsigned int no){
    DynamicVector<Expense> all = this->repo.getAll();
    for( int i=0; i<all.size(); i++){
        Expense ex =  all[i];
        if(no == ex.getNoApartment())
            return i;
    }
    return -1;
}
/*
 decr: Sum all type expenses
 in: type
 out:
 */
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
/*
 decr: Sum high of apartment
 in: no (apartment)
 out: index
 */
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
/*
 decr: Order descending for type
 in: type
 out:
 */
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
/*
 decr: sort expenses by all type
 in:
 out:
 */
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
/*
 decr: Filter expense by type
 in: type
 out:
 */
void Controller::filterByType(int typee){
    DynamicVector<Expense> all = this->repo.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(typee != ex.getExpenseType())
            this->repo.elimCostsOfApartment(ex);
    }
}
/*
 decr: Structure undo
 in:
 out:
 */

struct undo{
    DynamicVector<Expense> all;
}undo[100];

/*
 decr: Adds the list of objects in structure Undo
 in: i
 out: i (new i)
 */
void Controller::addUndo(int &i){
    undo[i].all = this->repo.getAll();
    i++;
}
/*
 decr: adds the list of items from the undo list
 in: index
 out:
 */
void Controller::undoSupport(int i){
    DynamicVector<Expense> all = undo[i].all;
    this->repo.clearAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        this->repo.addExpense(ex);
    }
}



