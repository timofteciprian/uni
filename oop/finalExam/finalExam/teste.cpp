//
//  teste.cpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "teste.hpp"
#include<cassert>
#include <vector>

void testCusca(){
    
    Cusca cus (0, 0, "leu", "africa", "mamifer");
    assert(cus.getTip() == "mamifer");
    assert(cus.getNume() == "leu");
    assert(cus.getZona() == "africa");

    cus.setNume("urs");
    assert(cus.getNume() == "urs");

}































































































































