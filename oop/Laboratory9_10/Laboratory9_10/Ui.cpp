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
void Ui::modifyAResource(){
    int command;
    string name;
    unsigned int date;
    int value;
    cout<<"Give the type of resource(1. Material / 2. Financial): ";
    cin>>command;
    cout<<"Give the name: ";
    cin>>name;
    cout<<"Give the date entry: ";
    cin>>date;
    cout<<"Give the value: ";
    cin>>value;
    if(command == 1){
        int lifeTime, no, co;
        cout<<"Give the lifetime: ";
        cin>>lifeTime;
        cout<<"Give the no: ";
        cin>>no;
        bool quit = true;
        
        while(quit){
            cout<<"1. Name. 2. Date Entry. 3. Value.  4. Life Time.  5.No.  0. Exit."<<endl;
            cout<<"Give what you want to change: ";
            cin>>co;
            switch (co) {
                case 0:{
                    quit = false;
                }break;
                case 1:{
                    string newname;
                    cout<<"Give new name: ";
                    cin>>newname;
                    ctrl.modifyAMaterial(name, date, value, lifeTime, no, newname, date, value, lifeTime, no);
                }break;
                case 2:{
                    unsigned int newdate;
                    cout<<"Give new date: ";
                    cin>>newdate;
                    ctrl.modifyAMaterial(name, date, value, lifeTime, no, name, newdate, value, lifeTime, no);
                }break;
                case 3:{
                    int newvalue;
                    cout<<"Give new value: ";
                    cin>>newvalue;
                    ctrl.modifyAMaterial(name, date, value, lifeTime, no, name, date, newvalue, lifeTime, no);
                }break;
                case 4:{
                    int newlifetime;
                    cout<<"Give new life time: ";
                    cin>>newlifetime;
                    ctrl.modifyAMaterial(name, date, value, lifeTime, no, name, date, value, newlifetime, no);
                }break;
                case 5:{
                    int newno;
                    cout<<"Give new no: ";
                    cin>>newno;
                    ctrl.modifyAMaterial(name, date, value, lifeTime, no, name, date, value, lifeTime, newno);
                }break;
            }
        }
    }
    else
        if(command == 2){
            int co;
            string coin;
            cout<<"Give the coin: ";
            cin>>coin;
            bool quit = true;
            
            while(quit){
                cout<<"1. Name. 2. Date Entry. 3. Value.  4. Life Time.  5.No.  0. Exit."<<endl;
                cout<<"Give what you want to change: ";
                cin>>co;
                switch (co) {
                    case 0:{
                        quit = false;
                    }break;
                    case 1:{
                        string newname;
                        cout<<"Give new name: ";
                        cin>>newname;
                        ctrl.modifyAFinancial(name, date, value, coin, newname, date, value, coin);
                    }break;
                    case 2:{
                        unsigned int newdate;
                        cout<<"Give new date: ";
                        cin>>newdate;
                        ctrl.modifyAFinancial(name, date, value, coin, name, newdate, value, coin);
                    }break;
                    case 3:{
                        int newvalue;
                        cout<<"Give new value: ";
                        cin>>newvalue;
                        ctrl.modifyAFinancial(name, date, value, coin, name, date, newvalue, coin);
                    }break;
                    case 4:{
                        string newcoin;
                        cout<<"Give new coin: ";
                        cin>>coin;
                        ctrl.modifyAFinancial(name, date, value, coin, name, date, value, newcoin);
                    }break;
                }
            }
        }
        else
            cout<<" The commmand does't exist.";
}

void Ui::run(){
    int com;
    bool quit = true;
   
    while(quit){
        
        mainSupport();
        cout<<"Give the order: ";
        cin>>com;
        
        switch(com){
                
            case 1:{
                if(login()){
                    cout<<"Login successfully"<<endl;
                    printAllResources();
                    bool quitt = true;
                   
                    while(quitt){
                        
                        mainOperations();
                        int comOp;
                        cout<<"Give the order: "<<endl;
                        cin>>comOp;
                        
                        switch (comOp) {
                            case 0:{
                                quitt = false;
                            }break;
                            
                            case 1:{
                                printAllResources();
                                searchSpecificResource();
                            }break;
                            
                            case 2:{
                                printAllResources();
                                modifyAResource();
                            }break;
                        }
                    }
                }else{cout<<"unsuccessfully";}
            }break;
            
            case 2:{
                cout<<endl;
                cout<<"bye bye";
                quit = false;
            }break;
        }
    }
}
