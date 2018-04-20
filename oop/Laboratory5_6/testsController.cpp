//
//  testsController.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 20/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testsController.hpp"
#include "Expense.hpp"
#include "Repository.hpp"
#include "Controller.hpp"

void testController() {
    Repository repo;
    Controller ctrl(repo);
    assert(ctrl.getAll().size()==0);
    ctrl.addExpense(1,1300,Expense::Gas);
    ctrl.addExpense(1,100,Expense::Electricity);
    ctrl.addExpense(1,150,Expense::Water);
    ctrl.addExpense(2,550,Expense::Gas);
    ctrl.addExpense(2,23,Expense::More);
    ctrl.addExpense(3,53,Expense::More);
    ctrl.addExpense(4,423,Expense::Electricity);
    ctrl.addExpense(5,5345,Expense::Water);
    ctrl.addExpense(6,200,Expense::Gas);
    unsigned int n=ctrl.getAll().size();
    Expense::ExpenseType typee;
    typee = Expense::ExpenseType::Electricity;
    ctrl.elimCostsOfApartment(1, 100, typee);
    assert(ctrl.getAll().size()==n-1);
    n-=1;
    int *array;
    int count = 3;
    array = new int[count];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    ctrl.elimCostsMoreApartments(count, array);
    
    assert(ctrl.getAll().size() == 3 );
    
    cout<<"Testele pentru clasa Controller au fost efectuale cu succes\n";
    
}
