//
//  main.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//
#include <iostream>
#include "testAccount.hpp"
#include "testRepository.hpp"
#include "testRepoT.hpp"
#include "Account.hpp"
#include "RepoT.hpp"
#include "RepoFile.hpp"
#include "Controller.hpp"
#include "Ui.hpp"
#include "testRepoFile.hpp"


int main(int argc, const char * argv[]) {
    
    testAccount();
    testRepoT();
    testRepoFile();
    RepoFile repo("test.txt");
    Controller ctrl(repo);
    Ui Ui(ctrl);
    Ui.run();
    return 0;
}
