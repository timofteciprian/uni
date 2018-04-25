//
//  main.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include <iostream>
#include "testAccount.hpp"
#include "testRepository.hpp"
#include <iostream>
#include "Repository.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    TestAccount accountTester = TestAccount();
    accountTester.runTests();
    
    TestRepo repoTester = TestRepo();
    repoTester.runTests();
    
    Repository<int> repo;
    vector<int> acc = repo.getAccounts();
    acc.push_back(25);
    
    cout << acc.front();
    
    return 0;
}
