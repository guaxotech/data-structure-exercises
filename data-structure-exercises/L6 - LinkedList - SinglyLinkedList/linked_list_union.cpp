#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

//Merges two lists into a third one, preserving the order.

#include "lista.hpp"
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

void uniao(No **lista1, No **lista2, No **listaSaida)
{
    No *n1 = *lista1;
    No *n2 = *lista2;
    No *nS = *listaSaida;

    while(n1 != NULL)
    {
        insereFinalL(listaSaida, n1->dado);
        n1 = n1->prox;
    }

    while(n2 != NULL)
    {
        insereFinalL(listaSaida, n2->dado);
        n2 = n2->prox;
    }
}
/**/

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");


   No *lista1 = NULL;
   No *lista2 = NULL;
   No *listaSaida = NULL;


   insereInicioL(&lista1, 20);
   insereInicioL(&lista1, 20);
   insereInicioL(&lista1, 20);
   insereInicioL(&lista1, 20);
   insereInicioL(&lista1, 20);

   insereInicioL(&lista2, 50);
   insereInicioL(&lista2, 50);
   insereInicioL(&lista2, 50);
   insereInicioL(&lista2, 50);
   insereInicioL(&lista2, 50);

   uniao(&lista1, &lista2, &listaSaida);

   mostraL(&listaSaida);








}
