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
    //~Controller();
    
    void addExpense(unsigned int no, unsigned int sum, Expense::ExpenseType tip);
    DynamicVector<Expense> &getAll();
    void elimCostsOfApartment(unsigned int);
};

#endif /* Controller_hpp */
