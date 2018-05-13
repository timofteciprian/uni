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
    Repository &repoF;
    RepositoryUser &repoUser;
    
public:
    
    Controller(Repository &repoM ,Repository &repoF, RepositoryUser &repoUser);
    
    bool findUser(string userName, string password);
    
    Resource** getMaterial();
    Resource** getFinancial();
    
    void searchSpecificMaterialByName(string name, int listIndex[], int &size);
    void searchSpecificFinancialByName(string name, int listIndex[], int &size);
    int searchSpecificResourceByDate(unsigned int date);
    int getSizeRepo();
    
    
};

#endif /* Controller_hpp */
