//
//  Repository.cpp
//  Laboratory 5-6
//
//  Created by Timofte Ciprian Andrei on 29/03/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Repository.hpp"
#include <iostream>
 
void Repository::addExpense(Expense ex){
    this->costs = this->costs + ex;
}

DynamicVector<Expense> &Repository::getAll(){
    return this->costs;
}

*/
void Repository::elimCostsOfApartment(unsigned int no){
    for(int i=0; i<)
}
*/
/*
 
 void elimiCostsMoreApartment(int d, unsigned int* l){
 for(int i=0; i<d; i++)
 for(int j=0; j<this->dim; j++)
 if(l[i] == cheltuieli[j]){
 cheltuieli[j] = cheltuieli[j+1];
 this->dim--;
 }
 }
 */


DynamicVector <Expense> operator + (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}

DynamicVector <Expense> operator + (const Expense &b, const DynamicVector <Expense> &a) {
    DynamicVector <Expense> ret = a;
    ret.push_back(b);
    return ret;
}

DynamicVector <Expense> operator - (const DynamicVector <Expense> &a, const Expense &b) {
    DynamicVector <Expense> ret = a;
    ret.remove(b);
    //ret.erase(remove(ret.begin(), ret.end(), b), ret.end());
    return ret;
}



/*
 Repository& Repository::operator=(const Repository &c){
 if (this == &c){
 this->sizeList = c.sizeList;
 this->countList = c.countList;
 
 delete[] this->costs;
 this->costs = new Expense[this->sizeList];
 
 for (int i = 0; i < this->countList; i++)
 this->costs[i] = c.costs[i];
 
 }
 return *this;
 }
 */
