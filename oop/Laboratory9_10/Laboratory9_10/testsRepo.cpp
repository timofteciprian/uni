//
//  testsRepo.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 18/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//
#include "Resource.hpp"
#include "Financial.hpp"
#include "Material.hpp"
#include "testsRepo.hpp"

void testsRepo(){
    Repository repo;
    ifstream fin;
    fin.open("fileFinancial.txt");
    Material *elem = new Material();
    fin >> elem ;
    repo.add(elem);
    assert(repo.getSize() == 1);
    
    fin>>elem;
    repo.add(elem);
    assert(repo.getSize() == 2);
    
    repo.modifyAFinancial("coco", 10, 10, "cue", "schimbate", 10, 10, "cue");
    
}





























































































































































void testMaterial(){}
void testFinancial(){}
