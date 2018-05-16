//
//  Repository.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 09/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include <stdio.h>
#include "Repository.hpp"
#include <iostream>
#include <string>
#include "Material.hpp"

Repository::Repository(){
    elements = new Resource*[20];
    //this->fileName = {};
    this->size = 0;
}
Repository::Repository(string fileName){
    if (fileName == "fileMaterial.txt")
        readMaterial(fileName);
    else
        readFinancial(fileName);
}

void Repository::readMaterial(string fileName){
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            Material *elem = new Material();
            fin >> elem ;
            add(elem);
            writeToFile("write.txt");
        }
        fin.close();
    }
    else
        cout << "No";
}
void Repository::readFinancial(string fileName){
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            Financial *elem = new Financial();
            fin >> elem ;
            add(elem);
        }
        fin.close();
    }
    else
        cout << "No";
}

Repository::~Repository(){
    if (elements){
        for(int i = 0; i < size; i++)
            if (elements[i]){
                delete elements[i];
                elements[i] = NULL;
            }
        delete[] elements;
        elements = NULL;
    }
}

void Repository::add(Resource* elem){
    //    for (int i = 0; i < size; i++){
    //        if (elem == elements[i])
    //            return;
    //    }
    if (size == 0){
        elements = new Resource*[100];
    }
    elements[size] = elem->clone();
    size++;
}

void Repository::writeToFile(const string fileName){
    ofstream fout;
    fout.open(fileName);
    for (int i = 0; i < size; i++)
        fout << elements[i];
    fout.close();
}

Resource** Repository::getAll(){
    return elements;
}
int Repository::getSize(){
    return size;
}

void Repository::loadFromFile(string fileName){
    if (fileName == "fileMaterial.txt")
        readMaterial(fileName);
    else
        if(fileName == "fileFinancial.txt")
            readFinancial(fileName);
        else
            cout << "Fisier corupt";
}
void Repository::modifyAMaterial(string name, unsigned int date, int value, int lifeTime, int no, string newname, unsigned int newdate, int newvalue, int newlifetime, int newno){
    for(int i=0; i<getSize(); i++){
        Material *elem = dynamic_cast<Material*>(elements[i]);
        if(elem != nullptr ){
            if(elem->Resource::getName() == name and elem->Resource::getDateEntry() == date and elem->Resource::getValue()==value and elem->getLifeTime()==lifeTime and elem->getNo()==no ){
                elem->Resource::setName(newname);
                elem->Resource::setDateEntry(newdate);
                elem->Resource::setValue(newvalue);
                elem->setLifeTime(newlifetime);
                elem->setNo(newno);
            }
        }
    }
}
void Repository::modifyAFinancial(string name, unsigned int date, int value,string coin, string newname, unsigned int newdate, int newvalue, string newcoin){
    for(int i=0; i<getSize(); i++){
        Financial *elem = dynamic_cast<Financial *>(elements[i]);
        if(elem != nullptr ){
            if(elem->Resource::getName() == name and elem->Resource::getDateEntry() == date and elem->Resource::getValue()==value and elem->getCoin()==coin ){
                elem->Resource::setName(newname);
                elem->Resource::setDateEntry(newdate);
                elem->Resource::setValue(newvalue);
                elem->setCoin(newcoin);
            }
        }
    }
}
