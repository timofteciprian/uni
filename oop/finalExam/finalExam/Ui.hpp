//
//  Ui.hpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include <stdio.h>
#include <string>
#include <stdio.h>
#include "Controller.hpp"

class Ui{
private:
    Controller &ctrl;
public:
    Ui(Controller &ctrl);
    
    void mainSupport();
    void add();
    void get();
    void program();
    void run();
};
#endif /* Ui_hpp */
