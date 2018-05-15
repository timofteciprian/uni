//
//  Controller.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

Controller::Controller(Repository &repoM ,Repository &repoF, RepositoryUser &repoUser):repoM(repoM), repoF(repoF), repoUser(repoUser){}

bool Controller::findUser(string userName, string password){
    User *users = repoUser.getAll();
    for (int i=0; i<repoUser.getSize(); i++){
        User user = users[i];
        if(user.getUserName() == userName and user.getPassword() == password)
            return true;
    }
    return false;
}
Resource** Controller::getFinancial(){
    return repoF.getAll();
}
Resource** Controller::getMaterial(){
    return repoM.getAll();
}

int Controller::getSizeRepo(){
    return repoF.getSize();
}

void Controller::searchSpecificMaterialByName(string name){
    Resource ** elements = repoM.getAll();
    for(int i=0; i<repoM.getSize(); i++){
        if(elements[i]->getName() == name){
            cout<<elements[i]->toString();
            repoM.writeToFile("write.txt");
        }
    }
}
void Controller::searchSpecificFinancialByName(string name){
    Resource ** elements = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++){
        if(elements[i]->getName() == name){
            cout<<elements[i]->toString();
            repoF.writeToFile("write.txt");
        }
    }
}
void Controller::searchSpecificMaterialByDate(unsigned int date){
    Resource ** elements = repoM.getAll();
    for(int i=0; i<repoM.getSize(); i++){
        if(elements[i]->getDateEntry() == date){
            cout<<elements[i]->toString();
            repoM.writeToFile("write.txt");
        }
    }
}
void Controller::searchSpecificFinancialByDate(unsigned int date){
    Resource ** elements = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++){
        if(elements[i]->getDateEntry() == date){
            cout<<elements[i]->toString();
            repoF.writeToFile("write.txt");
        }
    }
}


