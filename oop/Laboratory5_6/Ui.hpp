//
//  Ui.hpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include <stdio.h>
#include "Controller.hpp"

class Ui{
private:
    Controller &ctrl;
public:
    Ui(Controller &ctrl);
    
    void mainSupport();
    void addExpense();
    void printOneExpense(Expense&);
    void printAllCosts();
    void elimCostsOfApartment();
    int findIndex(unsigned int, unsigned int);
    void run();
    
    
};



#endif /* Ui_hpp */