//
//  Cusca.hpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Cusca_hpp
#define Cusca_hpp

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Cusca {
private:
    bool flamand;
    bool curatare;
    string nume;
    string zona;
    string tip;
    
    
public:
    Cusca();
    Cusca(bool f, bool c, string n, string z, string t);
    Cusca(const Cusca &c);
    ~Cusca();
    
    void setFlamand(bool f);
    void setCuratare(bool c);
    void setNume(string nume);
    void setZona(string zona);
    void setTip(string tip);

    
    bool getFlamand();
    bool getCuratare();
    string getNume();
    string getZona();
    string getTip();
    
    friend istream& operator>>( istream& input, Cusca &c );
    friend ostream& operator<<( ostream& output, Cusca &c );

};

#endif /* Animal_hpp */
