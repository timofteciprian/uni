//
//  testsRepository.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 30/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//
#include "Repository.hpp"
#include "Expense.hpp"
#include "testsRepository.hpp"
#include <assert.h>

void testRepo(){
    Expense c1 = Expense();
    Repository repo1;
    assert(repo1.getAll().size() == 0);
    repo1.addExpense(c1);
    assert(repo1.getAll().size() == 1);
    Repository repo2 = Repository();
    repo2.addExpense(c1);
    Expense c2 = Expense();
    Expense c3 = Expense();
    repo2.addExpense(c2);
    repo2.addExpense(c3);
    assert(repo2.getAll().size() == 3);

    repo2.clearAll();
    assert(repo2.getAll().size() == 0);
    Expense::ExpenseType typee;
    typee = Expense::ExpenseType::Gas;
    Expense ex = Expense(2, 20, typee);
    repo2.addExpense(ex);
    assert(repo2.getAll().size() == 1);


    cout << "Testele pentru clasa Repository au fost efectuate cu succes"<<endl;

}
    
