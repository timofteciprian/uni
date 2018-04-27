//
//  testAccount.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testAccount.hpp"
#include <iostream>
#include "Account.hpp"
#include <string>
#include <assert.h>

void testAccount() {
    Account c1 = Account();
    assert(c1.getPin() == 0);
    assert(c1.getName() == "");
    assert(c1.getId() == "");
    
    string name="Dorel";
    
    Account c2(name,"19854563652",1234);
    assert(c2.getName() == "Dorel");
    assert(c2.getId() == "19854563652");
    assert(c2.getPin() == 1234);
    
    c2.setPin(1010);
    assert(c2.getPin() == 1010);
    
    c2.setName("Andrei");
    assert(c2.getName() == "Andrei");
    
    cout << "tests passed successfully"<<endl;
}
