//
//  RepoFile.hpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef RepoFile_hpp
#define RepoFile_hpp

#include <stdio.h>
#include "RepoT.hpp"

class RepoFile : public RepoT<Account> {
public:
    
    RepoFile();
    RepoFile(char* fileName);
    virtual ~RepoFile();
    
    void loadFromFile(char *);
    void writeToFile(char *);
    
    
    
private:
    char* filename;
    RepoT<Account> clienti;
    
};


#endif /* RepoFile_hpp */
