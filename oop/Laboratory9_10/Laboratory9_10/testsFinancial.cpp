//
//  testsFinancial.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 18/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testsFinancial.hpp"

void testsFinancial(){
    Repository repo;
    ifstream fin;
    fin.open("fileFinancial.txt");
    Financial *elem = new Financial();
    fin >> elem ;
    repo.add(elem);
    assert(repo.getSize() == 1);
    
    repo.modifyAFinancial("coco", 10, 10, "cue", "schimbare", 10, 10, "cue");
    
    assert(elem->getName() == "schimbare");
    assert(elem->getValue() == 10);
    assert(elem->getDateEntry() == 10);
    assert(elem->getCoin() == "cue");
    
    
    assert(elem->getName() == "schimbare");
    assert(elem->getValue() == 10);
    assert(elem->getDateEntry() == 10 );
    assert(elem->getCoin()== "cue");
    
    elem->setName("ok");
    assert(elem->getName() == "ok");
    
    elem->setDateEntry(11111);
    assert(elem->getDateEntry() == 11111);
    
    elem->setValue(99);
    assert(elem->getValue() == 99);
    
    elem->setCoin("dada");
    assert(elem->getCoin() == "dada");
    
}
