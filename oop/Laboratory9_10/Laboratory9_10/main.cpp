//
//  main.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 08/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Repository.hpp"
#include "RepositoryUser.hpp"
#include "Ui.hpp"
#include "testsRepo.hpp"
#include "testsMaterial.hpp"
#include "testsFinancial.hpp"
#include <iostream>
#include <fstream>


int main(int argc, const char * argv[]) {
    
    testsRepo();
    testMaterial();
    testFinancial();

    Repository repoM("fileMaterial.txt");
    Repository  repoF("fileFinancial.txt");
    RepositoryUser repoUser("users.txt");
    Controller ctrl={repoM, repoF, repoUser};
    Ui ui{ctrl};
    ui.run();
    return 0;
};
