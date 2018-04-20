//
//  testsExpense.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 30/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testsExpense.hpp"
#include <assert.h>

void testExpense(){
    Expense expense;
    Expense::ExpenseType typpe = Expense::ExpenseType::Water;
    
    Expense ex (1,50,typpe);
    assert(ex.getExpenseType() == 0);
    assert(ex.getSum() == 50);
    assert(ex.getNoApartment() == 1);
    
    Expense expense1;
    Expense::ExpenseType typpe1 = Expense::ExpenseType::More;
    
    expense1.setNoApartment(10);
    assert(expense1.getNoApartment() == 10);
    
    expense1.setExpenseType(typpe1);
    assert(expense1.getExpenseType() == 4);
    
    expense1.setSum(100);
    assert(expense1.getSum() == 100);
    
    cout<<"Testele pentru clasa Expense au fost efectuale cu succes\n";
    
}
