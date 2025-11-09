#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

// Exercise: Split Dynamic Queue After Value N
// Description: Splits a dynamic queue F1 into F1 and F2, starting F2 at the first element after value N. F1 keeps elements up to N (inclusive).
// Prototype: void splitAfter(int N, Queue* F1, Queue* F2);


void exibirMenu();
void separaF(int n, Fila *f1, Fila *f2);
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Fila f2;
    int n;

    enfileiraF(&f1, 10);
    enfileiraF(&f1, 20);
    enfileiraF(&f1, 30);
    enfileiraF(&f1, 40);
    enfileiraF(&f1, 60);
    enfileiraF(&f1, 70);
    enfileiraF(&f1, 80);
    enfileiraF(&f1, 90);
    enfileiraF(&f1, 100);

    separaF(60, &f1, &f2);


    cout<<"F1: "<<endl;
    mostraF(&f1);
    cout<<"-----------------------"<<endl;
    cout<<"F2: "<<endl;
    mostraF(&f2);




}
void separaF(int n, Fila *f1, Fila *f2)
{
    bool achou = false;
    Fila fAux;

    while(!vaziaF(f1))
    {
        int valor = desenfileiraF(f1);

        if(valor == n)
        {
            achou = true;
            enfileiraF(&fAux, valor);
            break;
        }
        enfileiraF(&fAux, valor);
    }
    while(!vaziaF(f1))
    {
        int valor = desenfileiraF(f1);
        enfileiraF(f2, valor);
    }

    while(!vaziaF(&fAux))
    {
        int valor = desenfileiraF(&fAux);
        enfileiraF(f1, valor);
    }
}
