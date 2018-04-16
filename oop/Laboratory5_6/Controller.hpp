//
//  Controller.hpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Repository.hpp"

class Controller{
private:
    Repository &repo;
    
public:
    Controller(Repository &repo);
    
    void addExpense(unsigned int no, unsigned int sum, Expense::ExpenseType tip);
    DynamicVector<Expense> &getAll();
    void elimCostsOfApartment(unsigned int, unsigned int, Expense::ExpenseType);
    void elimCostsMoreApartments(int,int*);
    void replaceSumExpense(unsigned int no, unsigned int sum,unsigned int typee);
    int findExpenseByNoAndSum(unsigned int no, unsigned int typee);
    int findExpenseByNo(unsigned int no);
    int sumAllTypeExpense(int index);
    int sumHighOfApartment(unsigned int no);
    void orderDescendingForType(int typee);
    void sortByType();
};

#endif /* Controller_hpp */
