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
    cout<<"    --------------------------------------    Main    ----------------------------------------"<<endl;
    cout<<"       0. Exit."<<endl;
    cout<<"       1. Add the number and the expense of an apartment."<<endl;
    cout<<"       2. Show all costs"<<endl;
    cout<<"       3. Eliminate all the cost of an apartment."<<endl;
    cout<<"       4. Eliminating spending on some apartments."<<endl;
    cout<<"       5. Elimination of gas expenses from all apartments."<<endl;
    cout<<"       6. The old amount of type expensed is REPLACE from the apartment with the sum."<<endl;
    cout<<"       7. Print the apartament costs."<<endl;
    cout<<"       8. Print higher expenses than the amount for all apartments."<<endl;
    cout<<"       9. Print expenses with sum. "<<endl;
    cout<<"       10. Print sum for all expenses with type expense."<<endl;
    cout<<"       11. Print high sum of apartment."<<endl;
    cout<<"       12. Orders descending spending on the type of all apartments."<<endl;
    cout<<"       13. Remain only expenses on a type"<<endl;
 
    cout<<"   --------------------------------------------------------------------------------------------"<<endl;
}
/*
 Dscr: Add the number and the expense of an apartment.
 In: no,sum,com
 Out:
 */
void Ui::addExpense(){
    unsigned int no, sum, com= 0;
    string typee;
    cout<<"Give the number of the apartment: ";
    cin>>no;
    cout<<"Give the amount of the expense: ";
    cin>>sum;
    cout<<"Give the type of spending (Water, Heat, Electricity, Gas, More): ";
    cin>>typee;
    com = typeOfExpense(typee);
    Expense::ExpenseType expenseTyppe = Expense::ExpenseType::Water;
    switch (com) {
        case 0:
            expenseTyppe = Expense::ExpenseType::Water;     break;
        case 1:
            expenseTyppe = Expense::ExpenseType::Heat;      break;
        case 2:
            expenseTyppe = Expense::ExpenseType::Electricity; break;
        case 3:
            expenseTyppe = Expense::ExpenseType::Gas;       break;
        case 4:
            expenseTyppe = Expense::ExpenseType::More;      break;
    }
    this->ctrl.addExpense(no, sum, expenseTyppe);
}
/*
 Dscr: operator cin
 In:
 Out:
 */
ostream& operator<<(std::ostream& os, Expense::ExpenseType t  )
{
    switch(t)
    {
        case  0: os << "Water";      break;
        case  1: os << "Heat";       break;
        case  2: os << "Electricity";  break;
        case  3: os << "Gas";        break;
        case  4: os << "More";       break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}
/*
 Dscr: Print one expense
 In:-
 Out:no,sum,type
 */
void Ui::printOneExpense(Expense e){
    cout<<"Apartment with the number " << e.getNoApartment() << " has the sum of "<< e.getSum() << " for expense " << e.getExpenseType() << endl ;
}
/*
 Dscr: Print all expense
 In:-
 Out:
 */
void Ui::printAllCosts(){
    DynamicVector<Expense> all = this->ctrl.getAll();
    for (int i=0; i<all.size(); i++){
        Expense ex = all[i];
        printOneExpense(ex);
    }
    
}
/*
Dscr: Eliminate costs of apartament
In: no, sum
Out: expense
 */
void Ui::elimCostsOfApartment(){
    int no, sum;
    Expense::ExpenseType typpe;
    cout<<"Give the number of the apartment: ";
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
/*
 Dscr: Memory allocation for an array
 In:
 Out:
 */
void Ui::allocation(int &size, int* &array){
    int *newarray;
    size *= 2;
    newarray = new int[size];
    for(int i = 0 ; i < size / 2 ; ++ i)
            newarray[i] = array[i];
    delete [] array;
    array = newarray;
}
/*
 Dscr: Eliminate costs more apartments
 In: list (apartments to be removed)
 Out:
 */
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
/*
 Dscr: Searches for the place of an expense in the list
 In:   list(types)
 Out:
 */
int Ui::typeOfExpense(string typee){
    int com=0;
    string array[] = {"Water", "Heat", "Electricity", "Gas", "More"};
    for(int i=0; i<5; i++){
        if(array[i] == typee)
            com = i;
    }
    return com;
}
/*
 Dscr: Eliminate all expenses for on type
 In: type
 Out:
 */
void Ui::elimAllSpendingWithOneType(){
    int no, sum, com=0;
    string typee;
    cout<<"Give the type of spending of the apartment: ";
    cin>>typee;
    com = typeOfExpense(typee);
    Expense::ExpenseType typpe;
    DynamicVector<Expense> all = this->ctrl.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(ex.getExpenseType() == com){
            no = ex.getNoApartment();
            sum = ex.getSum();
            typpe = ex.getExpenseType();
            this->ctrl.elimCostsOfApartment(no,sum,typpe);
        }
    }
}
/*
 Dscr:Replace sum expense
 In: no, sum, type, new sum
 Out:
 */
void Ui::replaceSumExpense(){
    unsigned int no, newSum, com=0;
    string typee;
    cout<<"Give the number of the apartment: ";
    cin>>no;
    cout<<"Give the type of spending (Water, Heat, Electricity, Gas, More): ";
    cin>>typee;
    cout<<"Give NEW sum of the expense: ";
    cin>>newSum;
    com = typeOfExpense(typee);
    this->ctrl.replaceSumExpense(no, newSum, com);
}
/*
 Dscr:Print all expenses for one apartments
 In: no (apartment)
 Out: all expenses
 */
void Ui::printExpenseApartment(){
    int index;
    unsigned int no,sum, typee;
    cout<<"Give the number of apartment";
    cin>>no;
    index = this->ctrl.findExpenseByNo(no);
    DynamicVector<Expense> all = this->ctrl.getAll();
    cout<<endl;
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        sum = ex.getSum();
        typee = ex.getExpenseType();
        if(no == ex.getNoApartment())
            cout<<"Apartment with the number " << ex.getNoApartment() << " has the sum of "<< ex.getSum() << " for expense " <<ex.getExpenseType()<<endl;
    }
}
/*
 Dscr: Print expense with higher sum
 In: value
 Out:
 */
void Ui::printExpensesWithHigherSum(){
    unsigned int newSum;
    cout<<"Give the higher value";
    cin>>newSum;
    DynamicVector<Expense> all = this->ctrl.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(newSum < ex.getSum())
            cout<<"Apartment with the number " << ex.getNoApartment() << " has the sum of "<< ex.getSum() << " for expense " << ex.getExpenseType()<<endl;
    }
}
/*
 Dscr: Print expenses with sum
 In: sum
 Out:
 */
void Ui::printExpensesWithSumAllAp(){
    unsigned int sum;
    cout<<"Give the sum";
    cin>>sum;
    DynamicVector<Expense> all = this->ctrl.getAll();
    for(int i=0; i<all.size(); i++){
        Expense ex = all[i];
        if(sum == ex.getSum())
            cout<<"Apartment with the number " << ex.getNoApartment() << " has the sum of "<< ex.getSum() << " for expense " << ex.getExpenseType()<<endl;
    }
}
/*
 Dscr: Print total sum eith type expense
 In: type expense
 Out:
 */
void Ui::printTotalSumWithTypeEx(){
    int index;
    string typee;
    cout<<"Give the type of spending: ";
    cin>>typee;
    index = typeOfExpense(typee);
    cout<<endl;
    cout<<this->ctrl.sumAllTypeExpense(index);
}
/*
 Dscr: Print high sum of apartemnt
 In: no (apartment)
 Out:
 */
void Ui::printHighSumOfApartment(){
    unsigned int no;
    int index;
    cout<<"Give the number of apartment: ";
    cin>>no;
    index = this->ctrl.sumHighOfApartment(no);
    DynamicVector<Expense> all = this->ctrl.getAll();
    Expense ex = all[index];
    cout<<"Apartment with the number " << ex.getNoApartment() << " has the high sum of "<< ex.getSum() << " for expense " << ex.getExpenseType()<<endl;
}
/*
 Dscr: Order descending for expense type
 In: type(expense)
 Out:
 */
void Ui::orderDescendingForType(){
    int index;
    string typee;
    cout<<"Give the type of spending: ";
    cin>>typee;
    index = typeOfExpense(typee);
    this->ctrl.orderDescendingForType(index);
}
/*
 Dscr: Restore the last operation
 In:
 Out:
 */
/*
void Ui::undo(DynamicVector<Expense> all){
    this->ctrl.undo(all);
}
 */
/*
 Dscr: Only spends on a type
 In: type
 Out:
 */
void Ui::filterByType(){
    int index;
    string typee;
    cout<<"Give the type of spending: ";
    cin>>typee;
    index = typeOfExpense(typee);
    this->ctrl.filterByType(index);
}
/*
 Dscr: All other functions are called
 In:
 Out:
 */
void Ui::run(){
    int com, i=0;
    bool quit = true;
    bool ok = true;
    DynamicVector<Expense> alll;
    
    while(quit){
        printAllCosts();
        mainSupport();
        cout<<"Dati comanda: ";
        cin>>com;
        
        if(com != 14)
            ok = true;
        
        if(ok)
            this->ctrl.addUndo(i);
        ok=false;
        
       
        
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
                
            case 5:
                elimAllSpendingWithOneType();
                break;
                
            case 6:
                replaceSumExpense();
                break;
                
            case 7:
                printExpenseApartment();
                break;
                
            case 8:
                printExpensesWithHigherSum();
                break;
                
            case 9:
                printExpensesWithSumAllAp();
                break;
            
            case 10:
                printTotalSumWithTypeEx();
                break;
                
            case 11:
                printHighSumOfApartment();
                break;
                
            case 12:
                orderDescendingForType();
                break;
                
            case 13:
                filterByType();
                break;
                
            case 14:
                this->ctrl.undoSupport(i-1);
                i--;
                break;
        }
    }
}

