//
//  testRepository.hpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 19/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef testRepository_hpp
#define testRepository_hpp

#include <stdio.h>
#include "Account.hpp"
#include "Repository.hpp"

class TestRepo
{
public:
    TestRepo();
    ~TestRepo();
    
    void runTests();
};

#endif /* testRepository_hpp */
