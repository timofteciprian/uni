//
//  Controller.cpp
//  Lab9_10
//
//  Created by Timofte Ciprian Andrei on 10/05/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

Controller::Controller(Repository &repoM ,Repository &repoF, RepositoryUser &repoUser):repoM(repoM), repoF(repoF), repoUser(repoUser){}

bool Controller::findUser(string userName){
    User *users = repoUser.getAll();
    for (int i=0; i<repoUser.getSize(); i++){
        User user = users[i];
        if(user.getUserName() == userName)
            return true;
    }
    throw Exception("User not found.");
    return false;
}
Resource** Controller::getFinancial(){
    return repoF.getAll();
}
Resource** Controller::getMaterial(){
    return repoM.getAll();
}

int Controller::getSizeRepo(){
    return repoF.getSize();
}

void Controller::searchSpecificMaterialByName(string name){
    Resource ** elements = repoM.getAll();
    for(int i=0; i<repoM.getSize(); i++){
        if(elements[i]->getName() == name){
            cout<<elements[i]->toString();
            //repoM.writeToFile("write.txt");
        }
        else
            throw Exception("This material not found.");
    }
}
void Controller::searchSpecificFinancialByName(string name){
    Resource ** elements = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++){
        if(elements[i]->getName() == name){
            cout<<elements[i]->toString();
            //repoF.writeToFile("write.txt");
        }
        else
            throw Exception("This financial not found.");
    }
}
void Controller::searchSpecificMaterialByDate(unsigned int date){
    Resource ** elements = repoM.getAll();
    for(int i=0; i<repoM.getSize(); i++){
        if(elements[i]->getDateEntry() == date){
            cout<<elements[i]->toString();
            //repoM.writeToFile("write.txt");
        }
        else
            throw Exception("This material not found.");
    }
}
void Controller::searchSpecificFinancialByDate(unsigned int date){
    Resource ** elements = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++){
        if(elements[i]->getDateEntry() == date){
            cout<<elements[i]->toString();
            //repoF.writeToFile("write.txt");
        }
        else
            throw Exception("This financial not found.");
    }
}
void Controller::modifyAMaterial(string name, unsigned int date, int value, int  lifeTime, int no,string newname, unsigned int newdate, int newvalue, int newlifetime, int newno){
    repoM.modifyAMaterial(name, date, value, lifeTime, no,newname, newdate, newvalue, newlifetime, newno);
}

void Controller::modifyAFinancial(string name, unsigned int date, int value, string coin, string newname, unsigned int newdate, int newvalue, string newcoin){
    repoM.modifyAFinancial(name, date, value,coin,newname, newdate, newvalue, newcoin);
}
void Controller::writeToHTML() {
    ofstream fout;
    fout.open("write.html");
    
    vector<string> headerMaterial {
        "Name", "Date",  "Value", "Life Time", "No"
    };
    fout << "<table>\n" << "  <tr>\n";

    for( auto head : headerMaterial ) {
        fout << "    <th>" << head << "</th>\n";
    }
    fout << "  </tr>\n";
   
    Resource ** elements = repoM.getAll();

    for(int i=0; i<repoM.getSize(); i++) {
        Material *elem = dynamic_cast<Material*>(elements[i]);
        fout << "  <tr>\n";
        if(elem != nullptr ){

                fout << "    <td>" << elem->getName() << "</td>\n";
                fout << "    <td>" << elem->getDateEntry() << "</td>\n";
                fout << "    <td>" << elem->getValue() << "</td>\n";
                fout << "    <td>" << elem->getLifeTime() << "</td>\n";
                fout << "    <td>" << elem->getNo() << "</td>\n";
            
        }
        fout << "  </tr>\n";
    }
    fout << "</table>\n";
//
    vector<string> headerFinancial {
        "Name", "Date",  "Value",  "Coin"
    };
    fout << "<table>\n" << "  <tr>\n";
    for( auto head : headerFinancial ) {
        fout << "    <th>" << head << "</th>\n";
    }
    fout << "  </tr>\n";
   
    Resource ** elementss = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++) {
        Financial *ele = dynamic_cast<Financial*>(elementss[i]);
        fout << "  <tr>\n";
        if(ele != nullptr ){
            
            fout << "    <td>" << ele->getName() << "</td>\n";
            fout << "    <td>" << ele->getDateEntry() << "</td>\n";
            fout << "    <td>" << ele->getValue() << "</td>\n";
            fout << "    <td>" << ele->getCoin() << "</td>\n";
            
        }
        fout << "  </tr>\n";
    }
    fout << "</table>\n";
    fout.close();
}
void Controller::writeToCSV(){
  
    ofstream out;
    out.open ("write.csv");
    
    Resource ** elements = repoM.getAll();
    out<<"Name;Date;Value;Life Time;No, \n";
    for(int i=0; i<repoM.getSize(); i++) {
        Material *elem = dynamic_cast<Material*>(elements[i]);
        if(elem != nullptr ){
            
            out << elem->getName() << ";"<< elem->getDateEntry() << ";" <<elem->getValue() << ";" << elem->getLifeTime() << ";"<< elem->getNo() <<"\n";
            
        }
    }
    out<<"Name;Date;Value; Coin \n";
    Resource ** elementss = repoF.getAll();
    for(int i=0; i<repoF.getSize(); i++) {
        Financial *ele = dynamic_cast<Financial*>(elementss[i]);
    
        if(ele != nullptr ){
            
            out  << ele->getName()<<";"<< ele->getDateEntry()<<";" << ele->getValue() <<";" << ele->getCoin() << "\n";
            
        }
    }
    out.close();
}
