#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <climits>

using namespace std;

#include "lista_dupla.hpp"

// Exercise: Implements two functions for a doubly linked list — 
// one to remove all occurrences of a given value, 
// and another that returns a new list containing the N largest elements.


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Lista lista = Lista();

   /*

   /// Fun��o 1:
   insereFimL(&lista, 20);
   insereFimL(&lista, 20);
   insereFimL(&lista, 30);
   insereFimL(&lista, 20);
   insereFimL(&lista, 50);
   insereFimL(&lista, 20);


   mostraL(&lista);

   removeTodos(&lista, 20);

   mostraL(&lista);

   */


   /// Fun��o 2:

   Lista lSaida = Lista();

    insereFimL(&lista, 60);
    insereFimL(&lista, 20);
    insereFimL(&lista, 40);
    insereFimL(&lista, 30);
    insereFimL(&lista, 50);
    insereFimL(&lista, 10);

   lSaida = leMaiores(&lista, 3); // Aqui ele mostra os 3 maiores da lista

   mostraL(&lSaida);

   lSaida = leMaiores(&lista, 10); // Aqui ele retorna a lista com ordenada com todos os elementos

   mostraL(&lSaida);
}
