//
//  Expense.hpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Expense_hpp
#define Expense_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Expense{
    
public:
    enum ExpenseType {
        Water,
        Heat,
        Electricity,
        Gas,
        More
    };
    Expense();
    Expense(unsigned int nr, unsigned int sum, Expense::ExpenseType t );
    Expense(const Expense& );
    ~Expense();
    
    unsigned int getNoApartment();
    void setNoApartment(unsigned int nr);
    
    unsigned int getSum();
    void setSum(unsigned int s);
    
    ExpenseType getExpenseType();
    void setExpenseType(ExpenseType t);
    
    
private:
    unsigned int noApartment;
    unsigned int sum;
    ExpenseType typee;
};
#endif /* Expense_hpp */



