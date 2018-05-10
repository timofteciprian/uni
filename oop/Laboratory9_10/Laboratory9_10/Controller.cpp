//
//  Controller.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

Controller::Controller(Repository &repoM ,Repository &repo, RepositoryUser &repoUser):repoM(repoM), repo(repo), repoUser(repoUser){}

bool Controller::findUser(string userName, string password){
    User *users = repoUser.getAll();
    for (int i=0; i<repoUser.getSize(); i++){
        User user = users[i];
        if(user.getUserName() == userName and user.getPassword() == password)
            return true;
    }
    return false;
}
Resource* Controller::getFinancial(){
    return repo.getAll();
}
Resource* Controller::getMaterial(){
    return repoM.getAll();
}

int Controller::getSizeRepo(){
    return repo.getSize();
}

void Controller::searchSpecificResource(){
    
}



