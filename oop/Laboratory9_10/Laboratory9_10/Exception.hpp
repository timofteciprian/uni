//
//  Exception.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 17/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include "RepositoryUser.hpp"
#include "User.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class Exception{
private:
    const char* message;
    
    
public:
    Exception(const char* m);
    const char* getMessage();
};



#endif /* Exception_hpp */
