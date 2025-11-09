#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "lista.hpp"

/*Returns the value stored in the last node of the list.*/

int leFinalL(No **lista)
{
    No* n = *lista;

    while(n != NULL)
    {
        n = n->prox;
        if(n->prox == NULL)
            return (n->dado);
    }
}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   No *lista = NULL;

   insereInicioL(&lista, 20);
   insereInicioL(&lista, 15);
   insereInicioL(&lista, 16);
   insereInicioL(&lista, 47);
   insereInicioL(&lista, 25);
   insereInicioL(&lista, 89);

   cout << "Elemento final da Lista: " << leFinalL(&lista) << endl;










}

