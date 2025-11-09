#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

// Returns the total number of nodes in the list.
int totalL(No **lista)
{
    No *n = *lista;
    int total = 0;
    while(n != NULL)
    {
        total++;
        n = n->prox;
    }
    return total;
}
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No *lista = NULL;

    insereInicioL(&lista, 10);
    insereInicioL(&lista, 12);
    insereInicioL(&lista, 28);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 56);
    insereInicioL(&lista, 35);

    cout<< "Totais de Elementos na Lista: " << totalL(&lista) << endl;


}
