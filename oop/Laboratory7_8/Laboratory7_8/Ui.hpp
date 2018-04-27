//
//  Ui.hpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include <stdio.h>

#include "Controller.hpp"

class Ui {
public:
    Ui();
    
    Ui(const Controller &ctrl);
    
    void run();
    
private:
    Controller ctrl;
    void printMenu();
    void gimmeMoney();
    
    void addCont();
    
    void printClineti();
    void retragereNumerar();
    void adaugareNumerar();
    void verificareSoldATM();
    
};

#endif /* Ui_hpp */
