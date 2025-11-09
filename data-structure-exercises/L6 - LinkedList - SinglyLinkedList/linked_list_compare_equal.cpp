#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

// Compares two lists and returns true if they are identical.

bool igualL(No **lista1, No **lista2)
{
    No *n = *lista1;
    No *n2 = *lista2;

    if(n == NULL || n2 == NULL)
    {
        if(n == NULL && n2 == NULL)
        {
            cout<<"*OBS: Ambas as listas est�o vazias!"<<endl;
            return true;
        }
        cout<<"*OBS: Alguma das listas est� vazia! " <<endl;
        return false;
    }


    while(n != NULL && n2 != NULL)
    {
       if(n->dado != n2->dado)
        return false;

     n = n->prox;
     n2 = n2->prox;
    }
    if(n != NULL || n2 != NULL)
        return false;

    return true;
}


main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No *lista = NULL;
    No *lista2 = NULL;

    insereInicioL(&lista, 50);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 10);

    insereInicioL(&lista2, 50);
    insereInicioL(&lista2, 2);
    insereInicioL(&lista2, 8);

    if(igualL(&lista, &lista2))
    {
        cout<<"S�o iguais! " << endl;
    }
    else
    {
        cout<<"S�o diferentes! " << endl;
    }


}
