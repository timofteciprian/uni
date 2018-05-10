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
    // User user;
    //string userN, passw;
    input >> u.userName;
    //user.setUserName(userN);
    input >> u.password;
    //user.setPasssword(passw);
    return input ;
}

ostream& operator<<( ostream& output, User & u) {
    //User user;
    //string userN, passw;
    output << "User Name: "<< u.userName <<endl;
    //user.setUserName(userN);
    output << "Password: "<< u.password <<endl;
    //user.setPasssword(passw);
    return output ;
}



User& User::operator=(const User &u) {
    if (this != &u){
        userName = u.userName;
        password = u.password;
    }
    return *this;
}



