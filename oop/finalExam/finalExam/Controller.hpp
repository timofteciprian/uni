//
//  Controller.hpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Cusca.hpp"
#include "RepoFile.hpp"
#include "Repo.hpp"
#include <stdio.h>
#include  <vector>

class Controller {
private:
    RepoFile <Cusca> &  custi ;
    
public:
    Controller( RepoFile <Cusca> & custi);

    void addCusca(bool flamand, bool curatare, string nume, string zona, string tip  );
    void readFile();
    vector<Cusca> getCusti();
    vector<Cusca> programLucru(int &, int&);
};

#endif /* Controller_hpp */
