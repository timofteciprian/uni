//
//  Repository.hpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>

#include "Account.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Repository {
public:
    Repository(const vector<Account> &accounts);
    
    Repository();
    
    virtual ~Repository();
    
    const vector<Account> &getAccounts() const;
    
    void addElem(Account);
    void deleteElem(unsigned int);
    void update(unsigned int, Account);
    void populate();
    
private:
    vector<Account> accounts;
};


#endif /* Repository_hpp */
