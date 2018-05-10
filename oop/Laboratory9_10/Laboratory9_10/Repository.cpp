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
    //size = 0;
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


Resource* Repository::getAll(){
    return *elements;
}
int Repository::getSize(){
    return size;
}

//Material* Repository::getMaterial(){
//    Material* elem = new Material();
//    for(int i=0; i<size; i++){
//        //elem = elements[i]->clone();
//        return elements[i];
//    }
//}



//Repository::loadFromFile(char* fileName){
//    ifstream fin;
//    fin.open(fileName);
//    if (fin){
//        while (!fin.eof()){
//            T elem;
//            fin >> elem;
//            add(elem);
//        }
//        fin.close();
//    }
//    else
//        cout << "Fisier corupt";
//}
//
//template<class T> int Repository<T>::getPoz(T el){
//    for (int i = 0; i < size; i++){
//        if (elements[i] == el)
//            return i;
//    }
//    return -1;
//}
//
//template<class T> int Repository<T>::search(T elem){
//    for (int i = 0; i < size; i++){
//        if (elements[i] == elem)
//            return 1;
//    }
//    return 0;
//}

//template<class T> T Repository<T>::getElement(int poz){
//    return elements[poz];
//}
//

