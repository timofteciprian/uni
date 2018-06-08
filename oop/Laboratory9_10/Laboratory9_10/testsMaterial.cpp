//
//  testsMaterial.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 18/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "testsMaterial.hpp"


void testsMaterial(){
    Repository repo;
    ifstream fin;
    fin.open("fileMaterial.txt");
    Material *elem = new Material();
    fin >> elem ;
    repo.add(elem);
    assert(repo.getSize() == 1);
    
    repo.modifyAMaterial("Bureti", 20, 10, 12, 13, "schimbare",10, 10, 10, 10);
    
    
    assert(elem->getName() == "schimbare");
    assert(elem->getValue() == 10);
    assert(elem->getDateEntry() == 10 );
    assert(elem->getLifeTime()== 10);
    assert(elem->getNo()== 10);
    
    elem->setName("ok");
    assert(elem->getName() == "ok");
    
    elem->setDateEntry(11111);
    assert(elem->getDateEntry() == 11111);
    
    elem->setValue(99);
    assert(elem->getValue() == 99);
    
    elem->setNo(1892);
    assert(elem->getNo() == 1892);
   
    
}



























































































