#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha-dinamica.hpp"

// Function that copies elements from stack P1 to P2, preserving order and keeping P1 unchanged.

void copiarPilhas(Pilha *p1, Pilha *p2);

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   Pilha p2;

   empilhaP(&p1, 10);
   empilhaP(&p1, 15);
   empilhaP(&p1, 11);
   empilhaP(&p1, 32);
   empilhaP(&p1, 48);

   copiarPilhas(&p1, &p2);


   mostraP(&p1);
   cout<<"---------------------------------------"<<endl;
   mostraP(&p2);

}
void copiarPilhas(Pilha *p1, Pilha *p2)
{
    Pilha pAux;

    while(!vaziaP(p1))
    {
        int valor = desempilhaP(p1);
        empilhaP(&pAux, valor);
    }
    while(!vaziaP(&pAux))
    {
        int valor = desempilhaP(&pAux);
        empilhaP(p1, valor);
        empilhaP(p2, valor);
    }

}

