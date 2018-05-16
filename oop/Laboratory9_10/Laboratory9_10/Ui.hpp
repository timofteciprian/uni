//
//  Ui.hpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include "Controller.hpp"
#include <stdio.h>
#include <iostream>

class Ui{
private:
    
    Controller &ctrl;
public:
    
    Ui(Controller &ctrl);
    
    void mainOperations();
    void mainSupport();
    void printAllResources();
    bool login();
    void logout();
    void searchSpecificResource();
    void modifyAResource();
    void run();
    
};
#endif /* Ui_hpp */
