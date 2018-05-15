//
//  Ui.cpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Ui.hpp"
//
//  Ui.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Ui.hpp"
#include <iostream>
#include "Resource.hpp"

using namespace std;

Ui::Ui(Controller &ctrl): ctrl(ctrl) {
    //ctor
}

void Ui::mainSupport(){
    cout<<endl;
    cout<<"    ----------------------------------------    Main    ----------------------------------------"<<endl;
    cout<<"       0. Exit."<<endl;
    cout<<"       1. Login."<<endl;
    cout<<"       2. Logout."<<endl;
    cout<<"   ---------------------------------------------------------------------------------------------"<<endl;
}



bool Ui::login(){
    string userName, password;
    cout<<"Username: ";
    cin>>userName;
    cout<<"Password: ";
    cin>>password;
    if(this->ctrl.findUser(userName, password))
        return true;
    return false;
}

void Ui::printAllResources(){
    Resource** resF = ctrl.getFinancial();
    for(int i=0; i<ctrl.getSizeRepo(); i++ ){
        cout << resF[i]->toString();
    }
    Resource** resM = ctrl.getMaterial();
    for(int i=0; i<ctrl.getSizeRepo(); i++ ){
        cout << resM[i]->toString();
    }
}

void Ui::mainOperations(){
    cout<<endl;
    cout<<"    --------------------------------------    Main Operations    ----------------------------------------"<<endl;
    cout<<"       0. Exit."<<endl;
    cout<<"       1. Search for a specific resource (by name or after the date entered the company)."<<endl;
    cout<<"       2. Modify a specific resource."<<endl;
    cout<<"   ------------------------------------------------------------------------------------------------------"<<endl;
    
}

void Ui::searchSpecificResource(){
    int com;
    cout<< "1. By name."<<endl;
    cout<< "2. By the date entered the company"<<endl;
    cout<< "Give the order: ";
    cin>>com;
    if(com == 1){
        string name;
        cout<<"Give the name: ";
        cin>>name;
        ctrl.searchSpecificMaterialByName(name);
        ctrl.searchSpecificFinancialByName(name);
    }
    else
        if(com == 2){
            unsigned int date;
            cout<< "Give the date to entry: ";
            cin>>date;
            ctrl.searchSpecificMaterialByDate(date);
            ctrl.searchSpecificFinancialByDate(date);
        }
}


void Ui::run(){
    int com;
    bool quit = true;
    
    printAllResources();
    while(quit){
        
        mainSupport();
        cout<<"Give the order: ";
        cin>>com;
        
        switch(com){
            case 0:
                cout<<endl;
                cout<<"bye bye";
                quit = false;
                break;
                
            case 1:
                if(login()){
                    cout<<"Login successfully"<<endl;
                    mainOperations();
                    int comOp;
                    cout<<"Give the order: "<<endl;
                    cin>>comOp;
                    
                    switch (comOp) {
                        case 1:
                            searchSpecificResource();
                            break;
                            
                        default:
                            break;
                    }
                    break;
                    
                }
                else
                    //break;
                    cout<<"unsuccessfully";
                
            case 2:
                
                break;
                
            case 3:
                
                break;
                
        }
    }
}
