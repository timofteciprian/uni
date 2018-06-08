//
//  main.cpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 07/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include <iostream>
#include "RepoFile.hpp"
#include "Repo.hpp"
#include "Controller.hpp"
#include "Ui.hpp"
#include "Cusca.hpp"
#include "teste.hpp"


int main(int argc, const char * argv[]) {
    testCusca();
    RepoFile <Cusca> custi;
    Controller ctrl={custi};
    Ui ui{ctrl};
    ui.run();
    return 0;
}
