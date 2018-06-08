//
//  Ui.cpp
//  finalExam
//
//  Created by Timofte Ciprian Andrei on 08/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Ui.hpp"

Ui::Ui(Controller &ctrl): ctrl(ctrl) {
    //ctor
}
void Ui::mainSupport(){
    cout<<endl;
    cout<<"    ---------------------------------------    Main  ------------------------------------------"<<endl;
    cout<<"       0. Exit."<<endl;
    cout<<"       1. Adauga animal."<<endl;
    cout<<"       2. Afiseaza toate custile. "<<endl;
    cout<<"       3. Afisare animale hranite(4/ora) si custi ingrijite(2/ora)."<<endl;
    cout<<"   --------------------------------------------------------------------------------------------"<<endl;
}


void Ui::add(){
    string nume, zona, tip;
    cout<<"Dati numele: ";
    cin>>nume;
    cout<<"Dati zona: ";
    cin>>zona;
    cout<<"Dati tipul ";
    cin>>tip;
    ctrl.addCusca(true, true, nume, zona, tip);
}

void Ui::get(){
    vector<Cusca> custii = ctrl.getCusti();
    for(int i=0; i<custii.size(); i++)
        cout<<custii[i];
    cout<<endl;
}

void Ui::program(){
    int a=0,b=0;
    vector<Cusca> custii = ctrl.programLucru(a,b);
    for(int i=0; i<custii.size(); i++)
        cout<<custii[i];
    cout<<endl;
    cout<<"Animale hranite: "<<a<<endl<<"Custi curatate:  "<<b<<endl;
}

void Ui::run(){
    int com;
    bool quit = true;
    
    
    while(quit){
        
        mainSupport();
        cout<<"Dati comanda: ";
        cin>>com;
        ctrl.readFile();
        switch(com){
            case 0:
                cout<<endl;
                cout<<"bye bye";
                quit = false;
                break;
            
            case 1:
                add();
                break;
           
            case 2:
                get();
                break;
           
            case 3:
                program();
                break;
        }
    }
}
