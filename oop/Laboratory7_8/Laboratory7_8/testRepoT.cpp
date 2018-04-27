//
//  testRepoT.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testRepoT.hpp"
#include "Account.hpp"
#include "RepoT.hpp"
#include <iostream>
#include <assert.h>

using namespace std;

void testRepoT() {
    Account c1 = Account();
    
    RepoT <Account> repo1;
    
    assert(repo1.getSize() == 0);
    
    repo1.addAccount(c1);
    assert(repo1.getSize() == 1);
    
    RepoT <Account> repo2;
    
    repo2.addAccount(c1);
    
    Account c2 = Account();
    Account c3 = Account();
    repo2.addAccount(c2);
    repo2.addAccount(c3);
    
    assert(repo2.getSize()== 3);
    
    
    cout << "Testele pentru clasa RepoT au fost efectuate cu succes"<<endl;
    
}
