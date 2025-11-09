#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <climits>

using namespace std;

/**/
#include "lista.hpp"

void ordenarL(No **lista)
{
    No *anterior = NULL;
    No *atual = *lista;

    if(vaziaL(lista))   /// Retornar se estiver vazia
        return;

     No *n = *lista;
     int tam = 0;
     while(n != NULL)
     {
         tam++;
         n = n->prox;
     }

    while(atual->prox != NULL)
    {
        n = *lista;
        atual = atual->prox;

        while(n != NULL)
        {
           if(n->dado > atual->dado)
           {
               int aux = atual->dado;
               atual->dado = n->dado;
               n->dado = aux;

           }
           n = n->prox;
        }
    }


}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   No *lista = NULL;

   insereFinalL(&lista, 15);
   insereFinalL(&lista, 30);
   insereFinalL(&lista, 12);
   insereFinalL(&lista, 29);
   insereFinalL(&lista, 36);
   insereFinalL(&lista, 5);
   insereFinalL(&lista, 8);
   insereFinalL(&lista, 3);
   insereFinalL(&lista, 12);

   cout<<"Antes da ordenação: \n" <<endl;

   mostraL(&lista);

   cout<<"\n----------------------\n"<<endl;

   ordenarL(&lista);

   cout<<"Depois da ordenação: \n" << endl;

   mostraL(&lista);











}
