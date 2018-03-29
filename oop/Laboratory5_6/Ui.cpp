//
//  Ui.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//


#include <iostream>
#include <string>
#include "Ui.hpp"

Ui::Ui(Controller &ctrl): ctrl(ctrl) {
    //ctor
}

void Ui::mainSupport(){
    cout<<endl;
    cout<<"    ----------------------------    Main    ---------------------------------"<<endl;
    cout<<"       0. Inchide aplicatia."<<endl;
    cout<<"       1. Adauga numarul si cheltuiala unui apatament."<<endl;
    cout<<"       2. Afisarea tuturor cheltuielilor."<<endl;
    cout<<"       3. Elimina toate cheltielile unui apartament."<<endl;
    cout<<"       4. Eliminarea cheltueltuielilor unor apartmente."<<endl;
    cout<<"       5. Eliminarea cheluielilor cu gazul de la toate apartamentele."<<endl;
 
    cout<<"    --------------------------------------------------------------------------"<<endl;
}

void Ui::addExpense(){
    unsigned int no, sum;
    char tip1;
    Expense::ExpenseType tip;
    cout<<"Dati numarul apartmentului: ";
    cin>>no;
    cout<<"Dati suma cheltuielii: ";
    cin>>sum;
    cout<<"Dati tipul cheltuielii (Water, Heat, Electricy, Gas, More): ";
    cin.get();
    cin.get(tip1);
    tip = static_cast<Expense::ExpenseType> (tip1);
    this->ctrl.addExpense(no, sum, tip);
}

void Ui::printOneExpense(Expense &c){
    cout<<"Numarul apartamentului " <<c.getNoApartment() << " are suma de "<< c.getSum() << " pentru cheltuiala " << c.getExpenseType() << endl ;
}

void Ui::printAllCosts(){
    DynamicVector<Expense> all = this->ctrl.getAll();
    for (int i=0; i<all.size(); i++){
        Expense ex = all[i];
        printOneExpense(ex);
    }
    
}

int Ui::findIndex(unsigned int index,unsigned int no){
    DynamicVector<Expense> all = this->ctrl.getAll();
    for(int i=index; i<all.size(); i++){
        Expense ex = all[i];
        if(ex.getNoApartment() == no)
            return i;
    }
    return -1;
}


void Ui::elimCostsOfApartment(){
    unsigned int no,index;
    index=0;
    cout<<"Dati numarul apartamentului: ";
    cin>>no;
    if(findIndex(index,no) != -1)
        this->ctrl.elimCostsOfApartment(findIndex(index,no));
}

/*
     void elimAllGas(){
     this->ctrl.elimALlGas();
     }
     
     void elimiCostsMoreApartment(){
     int d, *l;
     bool stop = true;
     d=0;
     cout<<"--------- Se adauga numere pana la adugarea cifrei 0 ---------";
     cout<<"--------------Adaugati numere apoi dati ENTER----------------";
     while(stop){
     cout<<"Dati numarul: ";
     cin>>l[d];
     if(l[d] != 0)
     d++;
     else
     stop false;
     }
     d--;
     this->ctrl.elimCostsMoreApartment(d,l);
     }
*/
    
    
void Ui::run(){
    int com;
    bool quit = true;
    
    while(quit){
            
        mainSupport();
        cout<<"Dati comanda: ";
        cin>>com;
        
        switch(com){
            case 0:
                    cout<<endl;
                    cout<<"bye bye";
                    quit = false;
                    break;
                
            case 1:
                    addExpense();
                    break;
            
            case 2:
                    printAllCosts();
                    break;
                
        }
    }
}
    
inline istream& operator>>(istream &is, Expense::ExpenseType &e){
    
    return is;
}
