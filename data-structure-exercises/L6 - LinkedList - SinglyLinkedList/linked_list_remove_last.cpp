#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

/*Removes the last node from the list and returns its value.*/

#include "lista.hpp"

int removeFinalL(No **lista)
{
    No *anterior = NULL;
    No *atual = *lista;

    if(vaziaL(lista))
        return 0;

    while(atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = NULL;

    return atual->dado;
}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   No* lista = NULL;

   insereInicioL(&lista, 20);
   insereInicioL(&lista, 30);
   insereInicioL(&lista, 40);
   insereInicioL(&lista, 50);
   insereInicioL(&lista, 60);

   mostraL(&lista);

   cout<<"Elemento removido: " << removeFinalL(&lista)<<endl;;

   mostraL(&lista);












}
