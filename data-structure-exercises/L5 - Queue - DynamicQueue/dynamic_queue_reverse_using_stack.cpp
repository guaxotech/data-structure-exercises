#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

// Exercise: Reverse Dynamic Queue Using Stack
// Description: Implements a menu-based program to manage a dynamic queue and reverse its elements using a dynamic stack. Menu: enqueue, dequeue, show, reverse.
// Data Structure: Dynamic Queue + Dynamic Stack



void inverterElementos(Fila* f1);
void exibirMenu();
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;


    enfileiraF(&f1, 10);
    enfileiraF(&f1, 20);
    enfileiraF(&f1, 30);
    enfileiraF(&f1, 40);
    enfileiraF(&f1, 50);

    cout<<"Elementos antes da invers�o: "<<endl;
               mostraF(&f1);

    inverterElementos(&f1);

    cout<<"--------------------------------"<<endl;
    cout<<"Elementos ap�s a invers�o: "<<endl;

    mostraF(&f1);



}


void inverterElementos(Fila* f1)
{
    Pilha p1;

    while(!vaziaF(f1))
    {
        int valor = desenfileiraF(f1);
        empilhaP(&p1, valor);
    }
    while(!vaziaP(&p1))
    {
        int valor = desempilhaP(&p1);
        enfileiraF(f1, valor);
    }
}
