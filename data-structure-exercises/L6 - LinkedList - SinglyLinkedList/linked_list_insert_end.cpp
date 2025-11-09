#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

// Inserts a new node at the end of the list.

void insereFinalL(No **lista, int valor)
{
    No *n = *lista;
    No *novo = new No();
    novo->dado = valor;

    if(n == NULL)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    while(n->prox != NULL)
    {
       n = n->prox;
    }

    n->prox = novo;
    novo->prox = NULL;

}
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No *lista = NULL;

    /*insereInicioL(&lista, 10);
    insereInicioL(&lista, 12);
    insereInicioL(&lista, 28);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 56);
    insereInicioL(&lista, 35);
*/
    insereFinalL(&lista, 122);

    mostraL(&lista);
}
