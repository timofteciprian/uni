//
//  Controller.hpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "User.hpp"
#include "Repository.hpp"
#include "RepositoryUser.hpp"
#include <stdio.h>
#include <iostream>

class Controller{
private:
    
    Repository &repoM;
    Repository &repo;
    RepositoryUser &repoUser;
    
public:
    
    Controller(Repository &repoM ,Repository &repo, RepositoryUser &repoUser);
    
    bool findUser(string userName, string password);
    
    Resource* getMaterial();
    Resource* getFinancial();
    
    void searchSpecificResource();
    int getSizeRepo();
    
    
};

#endif /* Controller_hpp */
