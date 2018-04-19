//
//  testRepository.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testRepository.hpp"
#include "Account.hpp"
#include "Repository.hpp"
#include <assert.h>

void testRepository(){
    Account c1 = Account();
    Repository repo1 = Repository();
    assert(repo1.getAccounts().size() == 0);
    repo1.addElem(c1);
    assert(repo1.getAccounts().size() == 1);
    Repository repo2 = Repository();
    repo2.addElem(c1);
    Account c2 = Account();
    Account c3 = Account();
    repo2.addElem(c2);
    repo2.addElem(c3);
    assert(repo2.getAccounts().size() == 3);
    
    repo2.deleteElem(2);
    assert(repo2.getAccounts().size() == 2);
    Account c4 = Account("Name","cnp",1234);
    Account c5 = Account();
    Account c6 = Account();
    repo2.addElem(c4);
    repo2.addElem(c5);
    repo2.addElem(c6);
    repo2.deleteElem(1);
    repo2.deleteElem(3);
    assert(repo2.getAccounts().size() == 3);
    
    
    cout << "Tests for the Repository class have passed successfully"<<endl;
    
}
