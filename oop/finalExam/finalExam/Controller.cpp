//
//  Controller.cpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Controller.hpp"

Controller::Controller(RepoFile <Cusca> & custi) : custi(custi) {}

void Controller::readFile() {
    custi.setFile("fileName.txt");
    custi.addElement();
}

void Controller::addCusca(bool flamand, bool curatare, string nume, string zona, string tip){
    Cusca cus (flamand, curatare,nume, zona, tip);
    custi.addElem(cus);
}

vector<Cusca> Controller::getCusti(){
    return custi.getAll();
}

vector<Cusca> Controller::programLucru(int &a, int &b){
    vector<Cusca> custii = getCusti();
    int z=0,y=0;
    for(int i=6; i<=18; i++){
        for(int j=0; j<=4; j++){
            custii[z].setFlamand(true);
            z++;
        }
        for(int k=0; k<=2; k++){
            custii[y].setCuratare(true);
            y++;
        }
    }
    for(int i=0; i<custii.size() ;i++){
        if(custii[i].getFlamand() == 1)
            a++;
        if(custii[i].getCuratare()==1)
            b++;
    }
    return custii;
}
