//
//  main.cpp
//  finalProject
//
//  Created by Timofte Ciprian Andrei on 05/06/2018.
//  Copyright © 2018 Timofte Ciprian Andrei. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 100

using namespace std;

int NIL = 1; /// reprezinta un token neinitializat
int NUM = 2; /// reprezinta un token care contine un numar
int OP = 3; /// reprezinta un token care contine un operator

/**
 desc: implementarea structurii de token (contine tipul si valoarea -> ex: 23 este un token de tip numar cu valoarea 23, iar * este un token de tip operator cu valoarea *)
 **/
struct token {
    int type; /// tipul tokenului
    double val; /// valoarea tokenului
};

/**
 desc: implementarea structurii de vector de tip token
 **/
struct vect {
    token d[100]; /// vectorul de tip token
    int n; /// lungimea vectorului
};

/// initializarea unui vector de tip vect (a carui structura a fost implementata mai sus)
vect init_v() {
    vect ret; /// vectorul
    ret.n = 0; /// lungimea vectorului initializata cu 0
    return ret; /// returnarea vectorului
}

/**
 desc: functia de adaugare a unui element de tip token in vector
 in:
     vect &v = vectorul in care se adauga
     token t = elementul care se adauga (numar/operator)
out: vectorul modificat
 **/
void add(vect &v, token t) {
    v.d[v.n++] = t; /// adaugarea in vectorul d a elementului t pe pozitia n si cresterea numarului n (lungimea vectorului d)
}

/// returneaza tokenul de pe pozitia i din vector
token tokenAt(vect &v, int i) {
    return v.d[i];
}

vect out; /// in vectorul out se adauga elementele token in ordinea postfixata dupa ce acestea au fost scoase de pe stiva

/**
 desc: implementarea structurii de stiva
 **/
struct stiva {
    token v[MAX]; /// vectorul de token-uri
    int u; /// lungimea vectorului de token-uri
};

/**
 desc: initializarea stivei de token-uri
 **/
stiva init_s() {
    stiva s; /// stiva
    s.u = -1; /// pozitia ultimului element in stiva
    return s; /// returnarea stivei
}

/**
 desc: functia de adaugare a unui token pe stiva
 in:
 stiva &s = stiva in care se adauga token-ul
 token t = token-ul care se adauga
 out: stiva modificata
 **/
void push(stiva &s, token t) {
    s.v[++s.u] = t; /// adaugarea token-ului in stiva pe ultima pozitie
}

/**
 desc: functie ce determina daca o stiva este goala sau nu
 in: stiva &s = stiva care este verificata
 out: verdictul (true sau false, in functie de caz)
 **/
bool isEmpty(stiva &s) {
    return s.u == -1; /// returnarea verdictului
}

/**
 desc: functia de eliminare a unui element din stiva
 in: stiva &s = stiva de unde se elimina elementul
 out: stiva modificata
 **/
token pop(stiva &s) {
    if (!isEmpty(s)) /// verificare daca stiva este goala pentru a putea elimina elemente din ea
        return s.v[s.u--]; /// eliminarea din stiva a ultimului element
    cout << "Stiva este goala ";
    token t; /// initializarea unui token gol pentru evitarea erorilor legate de eliminarea dintr-o stiva goala
    t.type = NIL; /// token-ul t ia tipul token neitializat
    return t; /// returnarea token-ului pentru cazuri exceptionale (undefined behaviour)
}

/**
 desc: functia de returnare a ultimului element din stiva fara a-l elimina
 in: stiva &s = stiva de unde se returneaza ultimul element
 out: ultimul element din stiva
 **/
token top(stiva &s) {
    if (!isEmpty(s)) /// verificarea daca stiva este goala
        return s.v[s.u]; /// returnarea ultimului element din stiva
    cout << "Stiva este goala ";
    token t; /// initializarea unui token gol pentru evitarea erorilor legate de eliminarea dintr-o stiva goala
    t.type = NIL; /// token-ul t ia tipul token neitializat
    return t; /// returnarea token-ului pentru cazuri exceptionale (undefined behaviour)
}

stiva op; /// stiva de operatori


char operators[] = "()+-*/"; /// lista cu operatori

/**
 desc: verifica daca un caracter este operator
 in: char c = caracterul ce se verifica
 out: verdictul (true sau false, in functie de caz)
 **/
char* isOP(char c) {
    return strchr(operators, c); /// returnarea verdictului (true/false, in functie de caz)
}

/**
 desc: functia de stabilire a prioritatii a unui operator
 in: char c = operatorul care va fi verificat
 out: prioritatea (0 - pentru paranteze, 1 - pentru adunare si scadere sau 2 - pentru inmultire si impartire)
 **/
int prioritate(char c) {
    char *poz = strchr(operators, c); /// verificarea daca caracterul este un operator
    return (int)(poz - operators) / 2; /// prioritizarea
}

/**
 desc: functia adauga operatorul in stiva, in functie de prioritatea sa
 in: char c = operatorul
 out: stiva modificata
 **/
void operatorr(char c) {
    while (!isEmpty(op) && prioritate((char)top(op).val) >= prioritate(c)) /// verificarea daca un operator are o prioritate mai mare decat ultimul operator din stiva de operatori
        if (top(op).val != (double)'(' && top(op).val != (double)')')
            add(out, pop(op)); /// in caz afirmativ, se vor adauga operatorii in vectorul postfixat, pana cand conditia nu va mai fi implinita
        else
            pop(op); /// in caz contrar, se vor elimina operatori din stiva pana cand conditia nu va mai fi implinita
    token t;
    t.type = OP; /// initializarea unui token cu tipul operatie , iar, mai jos, cu valoarea caracterului citit
    t.val = (double)c;
    
    
    push(op, t); /// adaugarea token-ului pe stiva de operatori
}

/**
 desc: functia converteste un subsir de caractere in numere
 in: char* &c = subsirul de caractere
 out: token-ul cu valoare de numar
 **/
void digit(char* &c) {
    char buff[100]; /// sir de caractere unde se memoreaza textul inainte de a fi convertit
    int i = 0;
    do {
        buff[i++] = *c++;
    } while (isdigit(*c) || *c == '.'); /// prima parte din conversie
    --c;
    buff[i] = '\0';
    
    token t;
    t.type = NUM;
    t.val = atof(buff); /// conversia de la caracter la numar(float)
    add(out, t); /// adaugarea token-ului rezultat din conversie la vectorul postfixat
    
}

/// functia afiseaza un mesaj de tip eroare si va fi folosita pentru cazul in care stiva este goala
void err() {
    cerr << "Eroare de sintaxa" << endl;
}

/**
 desc: functia parcurge un sir de caractere si il converteste la numere si operatori in ordine postfixata
 in: char* c = sirul de caractere care se converteste
 out: sirul in ordine postfixata de numere si operatori
 **/
void in_to_post(char* c) {
    while (*c) {
        if (isdigit(*c)) /// verificare daca este numar
            digit(c); /// convertire la numar
        else if (isOP(*c)) /// verificare daca este operator
            operatorr(*c); /// convertire la operator
        else {
            err(); /// in cazul in care caracterul nu este nici numar, nici operator, se afiseaza mesajul de eroare
            return;
        }
        c++;
    }
    while (!isEmpty(op))
        if (top(op).val != (double)'(' && top(op).val != (double)')') /// verificarea daca este paranteza
            add(out, pop(op)); /// adaugarea in vectorul postfixat
        else
            pop(op); /// eliminarea din stiva fara a o adauga in vectorul postfixat
}
/**
 desc: implementarea structurii de arbore
 **/
struct tree {
    token t; /// initializarea unui token
    tree *left; /// initializarea subarborelui stang
    tree *right; /// initializarea subarborelui drept
};

/**
 desc: initializarea unui arbore
 **/
tree* init_t() {
    tree* r = new tree; /// initializarea unui nou arbore
    r->left = NULL; /// initializarea subarborelui stang cu NULL
    r->right = NULL; /// initializarea subarborelui drept cu NULL
    token t; /// initializarea unui token
    t.type = NIL; /// initializarea unui token cu tip neinitializat (NULL)
    t.val = -1.0;
    r->t = t; /// pune token-ul in arbore
    return r; /// returnarea arborelui
}

/**
 desc: functia construieste arborele binar care reprezinta expresia aritmetica
 in:
 token data[] = vectorul de token-uri
 int &s = pozitia de la care sa inceapa parcurgerea sirului de token-uri
 out: arborele
 **/
tree* construct(token data[], int &s) {
    tree* node = init_t(); /// initializarea arborelui
    node->t = data[s]; /// atribuirea sirului de token-uri
    
    if (data[s].type == OP) { /// verificarea daca tipul token-ului este operator
        node->right = construct(data, --s); /// construirea subarborelui drept
        node->left = construct(data, --s); /// construirea subarborelui stang
        
    }
    return node; /// returneaza arborele construit
}

/**
 desc: evaluarea expresiei aritmetice din arbore
 in: tree* r = arborele evaluat
 out: rezultatul expresiei
 **/
double evaluate(tree* r) {
    if (r) {
        if (r->t.type == NUM)
            return r->t.val;
        else if (r->t.type == OP) {
            char op = (char)(r->t.val);
            tree* left = r->left;
            tree* right = r->right;
            switch (op) {
                case '+':
                    return evaluate(left) + evaluate(right);
                case '-':
                    return evaluate(left) - evaluate(right);
                case '*':
                    return evaluate(left) * evaluate(right);
                case '/':
                    return evaluate(left) / evaluate(right);
            }
            
        }
    }
    return 0;
}

/**
 desc: functia de afisare a arborelui parcurs in inordine
 in: tree* r = arborele
 out: arborele afisat
 **/
void printInordine(tree* r) {
    if (r) {
        printInordine(r->left);
        if (r->t.type == OP)
            cout << (char)r->t.val << " ";
        else
            cout << r->t.val << " ";
        printInordine(r->right);
    }
}

/**
 desc: sterge arborele si il parcurge in inordine pentru a il goli din memorie
 in: tree* r = arborel
 out: -
 **/
void cleanup(tree* r) {
    if (r) {
        cleanup(r->left);
        delete r;
        cleanup(r->right);
    }
}

/// programul principal
int main(int argc, const char * argv[])
{
    out = init_v(); /// initializare vector de output
    op = init_s(); /// initializare stiva operatori
    char* text = new char[100]; /// citirea textului de la tastatura
    
    cout << "Introduceti o expresie aritmetica: ";
    cin >> text;
    
    in_to_post(text); /// conversia din inordine in postordine
    int s = out.n - 1; /// stiva de operatori
    tree* r = construct(out.d, s); /// initializare arbore
    cout << "= " << evaluate(r)<< endl;
    //inorder(r);
    printInordine(r);
    cout<<endl;
    
    cleanup(r); /// golire memorie
   
    return 0;
}
