//
//  Ui.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//


#include <iostream>
#include <string.h>
#include <cstring>
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
    unsigned int no, sum, com=0;
    string typee;
    cout<<"Give the number of the apartment: ";
    cin>>no;
    cout<<"Give the amount of the expense: ";
    cin>>sum;
    cout<<"Give the type of spending (Water, Heat, Electricy, Gas, More): ";
    cin>>typee;
    string array[] = {"Water", "Heat", "Electricy", "Gas", "More"};
    for(int i=0; i<5; i++){
        if(array[i] == typee)
            com = i;
    }
    Expense::ExpenseType expenseTyppe = Expense::ExpenseType::Water;
    switch (com) {
        case 0:
            expenseTyppe = Expense::ExpenseType::Water;     break;
        case 1:
            expenseTyppe = Expense::ExpenseType::Heat;      break;
        case 2:
            expenseTyppe = Expense::ExpenseType::Electricy; break;
        case 3:
            expenseTyppe = Expense::ExpenseType::Gas;       break;
        case 4:
            expenseTyppe = Expense::ExpenseType::More;      break;
    }
    this->ctrl.addExpense(no, sum, expenseTyppe);
}

ostream& operator<<(std::ostream& os, Expense::ExpenseType t  )
{
    switch(t)
    {
        case  0: os << "Water";      break;
        case  1: os << "Heat";       break;
        case  2: os << "Electricy";  break;
        case  3: os << "Gas";        break;
        case  4: os << "More";       break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}

void Ui::printOneExpense(Expense e){
    cout<<"Numarul apartamentului " << e.getNoApartment() << " are suma de "<< e.getSum() << " pentru cheltuiala " << e.getExpenseType() << endl ;
}

void Ui::printAllCosts(){
    DynamicVector<Expense> all = this->ctrl.getAll();
    for (int i=0; i<all.size(); i++){
        Expense ex = all[i];
        printOneExpense(ex);
    }
    
}

void Ui::elimCostsOfApartment(){
    int no, sum;
    Expense::ExpenseType typpe;
    cout<<"Dati numarul apartamentului: ";
    cin>>no;
    DynamicVector<Expense> all = this->ctrl.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(ex.getNoApartment() == no){
            sum = ex.getSum();
            typpe = ex.getExpenseType();
            this->ctrl.elimCostsOfApartment(no,sum,typpe);
        }
    }
}

void Ui::allocation(int &size, int* &array){
    int *newarray;
    size *= 2;
    newarray = new int[size];
    for(int i = 0 ; i < size / 2 ; ++ i)
            newarray[i] = array[i];
    delete [] array;
    array = newarray;
}

void Ui::elimCostsMoreApartments(){
    int size,count, *array, no;
    count=0;
    size=2;
    array = new int[size];
    bool stop = true;
    cout<<"--------------------      Add numbers until you add 0       ----------------------"<<endl;
    cout<<"--------------------       Add one number then ENTER        ----------------------"<<endl;
    while(stop){
        cout<<"Give the number: ";
        cin>>no;
        if(no != 0){
            if(size == count)
                allocation(size,array);
            array[count] = no;
            count++;
        }
        else
            stop = false;
        }
    this->ctrl.elimCostsMoreApartments(count,array);
    delete[] array;
}

    
    
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
                
            case 3:
                elimCostsOfApartment();
                break;
                
            case 4:
                elimCostsMoreApartments();
                break;
                
                
                
        }
    }
}
    
inline istream& operator>>(istream &is, Expense::ExpenseType &e){
    
    return is;
}
