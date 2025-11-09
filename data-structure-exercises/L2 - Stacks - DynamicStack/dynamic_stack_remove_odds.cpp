#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha-dinamica.hpp"

// Function that removes all odd elements from a dynamic stack, keeping the order of remaining elements.

void removerImpares(Pilha *p1);

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   empilhaP(&p1, 56);
   empilhaP(&p1, 23);
   empilhaP(&p1, 98);
   empilhaP(&p1, 79);
   empilhaP(&p1, 88);

   cout<<"Pilha contendo elementos Pares e �mpares: "<<endl;

   mostraP(&p1);

   removerImpares(&p1);

   cout<<"Pilha contendo somente elementos Pares: "<<endl;

   mostraP(&p1);


}
void removerImpares(Pilha *p1)
{
    Pilha pAux;

    while(!vaziaP(p1))
    {
        int valor = desempilhaP(p1);

        if(valor % 2 == 0)
        {
        empilhaP(&pAux, valor);
        }
    }
    while(!vaziaP(&pAux))
    {
        int valor = desempilhaP(&pAux);
        empilhaP(p1, valor);
    }
}
