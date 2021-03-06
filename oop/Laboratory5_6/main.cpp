//
//  main.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include <iostream>
#include "Repository.hpp"
#include "Controller.hpp"
#include "Ui.hpp"
#include "testsExpense.hpp"
#include "testsController.hpp"
#include "testsRepository.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    testExpense();
    testRepo();
    testController();
    
    Repository repo;
    Controller ctrl(repo);
    Ui ui(ctrl);
    ui.run();
    
    return 0;
}

