//
//  Repository.hpp
//  Laboratory9_10
//
//  Created by Timofte Ciprian Andrei on 06/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include "Resource.hpp"

using namespace std;

template<class T>class Repository{
private:
    int size;
    T* elements;
    string fileName;
    
public:
    Repository();
    Repository(string fileName);
    ~Repository();
    
    //    void writeToFiśe();
    void add(T elem);
    //    int search(T elem);
    //    int getPoz(T elem);
    //    T* getAll();
    //    T getElement(int poz);
    //    int getsize();
    //void loadFromFile(const char* fileName);
    void writeToFile(const string fileName);
    inline T& operator [] (int pos) {
        return elements[pos];
    }
};

template<class T> Repository<T>::Repository(){
    this->elements = new T[20];
    //this->fileName = {};
    this->size = 0;
}
template<class T> Repository<T>::Repository(string fileName){
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            T elem;
            //fin >> elem;
            
           // cout<<elem;
            //add(elem);
            
        }
        writeToFile("write.txt");
        fin.close();
    }
    else
        cout << "Fisier corupt";
}
template<class R> Repository<R>::~Repository(){
}

template<class T>
void Repository<T>::add(T elem){
//    for (int i = 0; i < size; i++){
//        if (elem == elements[i])
//            return;
//    }
    if (size == 0){
        elements = new T[100];
    }
    //cout<<elem;
    elements[size] = elem.clone();
    size++;
}
//Resource* newResource = new Resource();
//newResource->setName(this->name);


template<class T> void Repository<T>::writeToFile(const string fileName){
    ofstream fout;
    fout.open(fileName);
    for (int i = 0; i < size; i++)
        fout << elements[i];
    fout.close();
}


template<class T> void Repository<T>::loadFromFile(char* fileName){
    ifstream fin;
    fin.open(fileName);
    if (fin){
        while (!fin.eof()){
            T elem;
            fin >> elem;
            add(elem);
        }
        fin.close();
    }
    else
        cout << "Fisier corupt";
}

template<class T> int Repository<T>::getPoz(T el){
    for (int i = 0; i < size; i++){
        if (elements[i] == el)
            return i;
    }
    return -1;
}

template<class T> int Repository<T>::search(T elem){
    for (int i = 0; i < size; i++){
        if (elements[i] == elem)
            return 1;
    }
    return 0;
}

template<class T> T* Repository<T>::getAll(){
    return elements;
}



template<class T> T Repository<T>::getElement(int poz){
    return elements[poz];
}

template<class T> int Repository<T>::getsize(){
    return size;
}


#endif /* Repository_hpp */
