//
//  Ui.cpp
//  Laboratory7_8
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Ui.hpp"


Ui::Ui(Repository<Account> &repo): repo(repo) {
    //ctor
}

void Ui::mainSupport(){
    cout<<endl;
    cout<<"    --------------------------------------    Main    ----------------------------------------"<<endl;
    cout<<"       0. Exit."<<endl;
    cout<<"       1. Intra in cont."<<endl;
    cout<<"       "<<endl;
}

void logIn(){
    
    
}


void Ui::run(){
    int com;
    bool quit = true;
    
    cout<<"  0. Exit."<<endl;
    cout<<"  1. Intra in cont."<<endl;
    cout<<"Dati comanda:  ";
    cin>>com;
    logIn();
    
    while(quite){
        cout<<"  0. Exit."<<endl;
        cout<<"  1. Intra in cont."<<endl;
        cout<<"Dati comanda:  ";
        cin>>com;
    
        if( com == 1){
            
        }
    
        
        
        
    }
    
    
}
