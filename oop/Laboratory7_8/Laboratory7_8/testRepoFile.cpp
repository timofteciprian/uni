//
//  testRepoFile.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testRepoFile.hpp"
#include <assert.h>
#include "RepoT.hpp"
#include "RepoFile.hpp"

void testRepoFile() {
    RepoT<Account> repo;
    assert(repo.getSize()==0);
    
    repo.addAccount(Account("andrei", "1242453434", 3333));
    repo.addAccount(Account("ana", "7567657664", 1234));
    repo.addAccount(Account("matei", "6234233343", 6666));
    
    assert(repo.getSize()==3);
    
    
    cout << "Testele pentru RepoFile au fost efectuate cu succes!";
}
