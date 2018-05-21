//
//  User.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "User.hpp"
#include <iostream>
#include <string>
using namespace std;

User::User(){
    userName = {};
    password = {};
}

User::User(string &userName, string &password){
    userName = userName;
    password = password;
}

User::User(User& u){
    userName = u.userName;
    password = u.password;
}

User::~User(){}

string User::getUserName(){
    return userName;
}
void User::setUserName(string userName){
    userName = userName;
}

string User::getPassword(){
    return password;
}
void User::setPasssword(string password){
    password = password;
}

istream& operator>>( istream& input, User & u) {
    input >> u.userName;
    input >> u.password;
    return input ;
}

ostream& operator<<( ostream& output, User & u) {
    output << "User Name: "<< u.userName <<endl;
    output << "Password: "<< u.password <<endl;
    return output ;
}



User& User::operator=(const User &u) {
    if (this != &u){
        userName = u.userName;
        password = u.password;
    }
    return *this;
}



