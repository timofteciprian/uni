//
//  testsRepository.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 30/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testsRepository.hpp"
#include <assert.h>

void testRepo(){
    Repository repo = Repository();
    
    Expense::ExpenseType typpe;
    typpe = Expense::ExpenseType::Water;
    
    Expense ex (1,50,typpe);
    repo.addExpense(ex);
    assert(repo.getAll().size() == 1);

}

    
