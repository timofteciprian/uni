//
//  Exception.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 17/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(const char* m) : message(m){
}

const char* Exception::getMessage(){
    return this->message;
}
