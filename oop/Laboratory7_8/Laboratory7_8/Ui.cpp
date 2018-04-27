//
//  Ui.cpp
//  Lab78
//
//  Created by Timofte Ciprian Andrei on 26/04/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include "Ui.hpp"

//Ui::Ui() {}

Ui::Ui(const Controller &ctrl) : ctrl(ctrl) {}

void Ui::run() {
    int cmd=-1;
    this->gimmeMoney();
    while (cmd != 0) {
        this->printMenu();
        cout<<"Dati numarul comenzii: \n";
        cin>>cmd;
        switch (cmd) {
            case 1:{
                this->addCont();
                break;
            }
            case 2:{
                this->retragereNumerar();
                break;
            }
            case 3:{
                this->adaugareNumerar();
                break;
            }
            case 4:{
                this->verificareSoldATM();
                break;
            }
            case 5:
            {
                this->printClineti();
                break;
            }
            case 0:{
                cout << "O zi buna!";
                break;
            }
            default:{
                cout << "Numar operatie necunoscut, reintroduceti un numar corect\n";
                break;
            }
        }
    }
    
}

void Ui::printMenu() {
    cout<<"\n";
    cout << "0 - Iesire din aplicatie\n";
    cout << "1 - Adaugare cont\n";
    cout << "2 - Retragere numerar\n";
    cout << "3 - Depunere numerar\n";
    cout << "4 - Verificare sold ATM\n";
    cout << "5 - Afiseaza lista cu clienti\n\n";
}

//seteaza suma de bani disponibila in ATM
void Ui::gimmeMoney() {
    unsigned int suma;
    cout<<"\nDati suma de bani disponibila in ATM: ";
    cin>>suma;
    ctrl.setSuma(suma);
}

//adauga cont
void Ui::addCont() {
    string nume, cnp;
    unsigned int pin;
    cout << "Dati numele clientului: ";
    cin>>nume;
    cout << "Dati cnp-ul clientului: ";
    cin>>cnp;
    cout<<"Dati pin-ul clientului: ";
    cin>>pin;
    ctrl.addAccount(nume, cnp, pin);
    
}

//afiseaza lista de conturi
void Ui::printClineti() {
    for (Account c : ctrl.getClienti()) {
        cout<<"Clinetul "<<c.getName()<<" cu cnp-ul "<<c.getId()<<" are pin-ul "<<c.getPin()<<"\n";
    }
    cout<<"\n";
    
}

//actualizeaza suma de bani disponibila in ATM dupa retragere
void Ui::retragereNumerar() {
    unsigned int suma;
    cout<<"Dati suma ce va fi retrasa din ATM: ";
    cin>>suma;
    if (suma <= ctrl.getSuma()) {
        ctrl.setSuma(ctrl.getSuma() - suma);}
    else {
        cout<<"ATM-ul nu dispune de aceasta suma de bani, va rugam introduceti alta suma.\n";
        this->retragereNumerar();
    }
    
}
//actualizeaza suma de bani disponibila in ATM dupa depunere
void Ui::adaugareNumerar() {
    unsigned int suma;
    cout << "Dati suma ce va fi depusa in ATM: ";
    cin>>suma;
    ctrl.setSuma(ctrl.getSuma() + suma);
    
}
//afiseaza sold-ul disponibil in ATM
void Ui::verificareSoldATM() {
    cout<<"Suma disponibila in ATM este: "<<ctrl.getSuma()<<"ron\n";
    
}
