//
//  Ui.hpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include "Repository.hpp"
#include <stdio.h>

class Ui{
private:
    Repository<Account> &repo;
public:
    Ui(Repository<Account> &repo);
    
    void mainSupport();
    bool logIn();
    
    void run();
};


#endif /* Ui_hpp */
