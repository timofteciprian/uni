//
//  RepositoryUser.hpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef RepositoryUser_hpp
#define RepositoryUser_hpp

#include <stdio.h>

#include "User.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RepositoryUser {
private:
    
    User* users;
    int size;
    
public:
    
    RepositoryUser();
    RepositoryUser(string fileName);
    ~RepositoryUser();
    
    User* getAll();
    int getSize();
    void add(User user);
    
    RepositoryUser& operator=(const RepositoryUser &r);
};


#endif /* RepositoryUser_hpp */
