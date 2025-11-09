#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

// Exercise: Reorder Dynamic Queue (Even/Odd Transformation)
// Description: Keeps even numbers in original order and reverses the order of odd numbers using both a dynamic queue and a dynamic stack.


void exibirMenu();
void organizarParImpar(Fila* f1);
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 9);
    enfileiraF(&f1, 8);
    enfileiraF(&f1, 7);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 6);

    cout<<"Elementos da fila: "<<endl;
    mostraF(&f1);

    organizarParImpar(&f1);
    cout<<"Elementos da fila ap�s a organiza��o dos elementos: "<<endl;
    mostraF(&f1);

    destroiF(&f1);

}
void organizarParImpar(Fila* f1)
{
    Fila fPar;
    Fila fImpar;
    Pilha pAux;

    while(!vaziaF(f1))
    {
        int valor = desenfileiraF(f1);
        if(valor % 2 == 0)
        {
            enfileiraF(&fPar, valor);
        }
        else
        {
            enfileiraF(&fImpar, valor);
        }
    }
    while(!vaziaF(&fPar))
    {
        int valor = desenfileiraF(&fPar);
        enfileiraF(f1, valor);
    }

    while(!vaziaF(&fImpar))
    {
        int valor = desenfileiraF(&fImpar);
        empilhaP(&pAux, valor);
    }
    while(!vaziaP(&pAux))
    {
        int valor = desempilhaP(&pAux);
        enfileiraF(f1, valor);
    }

}

