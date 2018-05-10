//
//  User.hpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class User {
private:
    string userName;
    string password;
    
public:
    
    User();
    User(string &userName, string &password);
    User(User& u);
    ~User();
    
    string getUserName();
    void setUserName(string userName);
    
    string getPassword();
    void setPasssword(string password);
    
    
    User& operator=(const User &u);
    
    friend istream& operator >> (istream& input, User &u);
    friend ostream& operator << (ostream& output, User &u);
};

#endif /* User_hpp */
