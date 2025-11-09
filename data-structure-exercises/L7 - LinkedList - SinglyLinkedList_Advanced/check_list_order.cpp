#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "lista.hpp"

/**/


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

int verificaOrdem(No **lista)
{
    bool crescente = true;
    bool decrescente = true;

    No *anterior = NULL;
    No *atual = *lista;


    /// Testando para ver se está em ordem crescente:

    while(atual->prox != NULL)
    {
     anterior = atual;
     atual = atual->prox;
       if(anterior->dado > atual->dado)
       {
           //cout<<"ACHOU CRESCENTE FALSE: " << anterior->dado << " " << atual->dado << endl;
           crescente = false;
           break;
       }
    }

    anterior = NULL;
    atual = *lista;

    /// Testando para ver se está em ordem decrescente:

    while(atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        if(anterior->dado < atual->dado)
        {
            //cout<<"ACHOU DECRESCENTE FALSE: " << anterior->dado << " " << atual->dado << endl;
            decrescente = false;
            break;
        }
    }

    if(crescente)
    {
       return 0;
    }
    else if(decrescente)
    {
        return 1;
    }
    else if(!crescente && !decrescente )
    {
        return 2;
    }

}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   No *lista = NULL;

   insereFinalL(&lista, 20);
   insereFinalL(&lista, 18);
   insereFinalL(&lista, 16);
   insereFinalL(&lista, 14);
   insereFinalL(&lista, 12);
   insereFinalL(&lista, 10);

   mostraL(&lista);

   int resultado = verificaOrdem(&lista);

   if(resultado == 1)
   {
       cout<<"\n->CRESCENTE"<<endl;
   }
   else if(resultado == 2)
   {
       cout<<"\n->DECRESCENTE"<<endl;
   }
   else if(resultado == 3)
   {
       cout<<"NÂO ESTÁ ORDENADA! "<<endl;
   }








}
