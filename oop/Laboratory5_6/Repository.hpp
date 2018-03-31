//
//  Repository.hpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include "Expense.hpp"
#include "DynamicVector.hpp"


class Repository{
private:
        DynamicVector <Expense> costs;
    
public:
    
        void addExpense(Expense ex);
        DynamicVector <Expense>& getAll();
        void elimCostsOfApartment(Expense );
/*
         void replacesGas(unsigned int nr, unsigned int sum);
         void getCostsOfApartment(unsigned int nr);
         void getCostsGreaterValue(unsigned int s);
         void getCostsAValue(unsigned int s);
         void getSumGasAll();
         void maximCost(unsigned int nr);
         void sortDescendingGas();
         void filterJustGas();
         void filterLessValue(unsigned int s);
         void undo();
         
     */
};
DynamicVector <Expense> operator + (const DynamicVector <Expense> &a, const Expense &b);
DynamicVector <Expense> operator + (const Expense &b, const DynamicVector <Expense> &a);
DynamicVector <Expense> operator - (const DynamicVector <Expense> &a, const Expense &b);

#endif /* Repository_hpp */
