#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha.hpp"

// Merges two stacks (P1 and P2) into a third stack (P3), alternating elements from each.
// Preserves the relative order of elements in each input stack.
// Assumes P1 and P2 may have different numbers of elements.
// Complexity: O(n)


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;
   Pilha p2;
   int tamP1, tamP2;

   cout<<"Tamanho da Pilha 1 e 2: "<<endl;
   cin>>tamP1;

   tamP2 = tamP1;

   inicializaP(&p1, tamP1);

   inicializaP(&p2, tamP2);

   for(int i=0; i<tamP1; i++)
   {
       int elemento;
       cout<<"Elemento " << i+1 << " da Pilha 1: (Digite 0 para finalizar a entrada nessa pilha)"<<endl;
       cin >> elemento;

       if(elemento == 0)
        break;

       empilhaP(&p1, elemento);
   }

   for(int i=0; i<tamP2; i++)
   {
       int elemento;
       cout<<"Elemento " << i+1 << " da Pilha 2: (Digite 0 para finalizar a entrada nessa pilha)"<<endl;
       cin >> elemento;

       if(elemento == 0)
        break;

       empilhaP(&p2, elemento);
   }
   cout<<"P1: "<<endl;
   mostraP(&p1);

   cout<<"\n";

   cout<<"P2: "<<endl;
   mostraP(&p2);

   Pilha p3;

   inicializaP(&p3, (tamP1 + tamP2));

   for(int i=0; i <(p3.tam); i++ )
   {
       if(!vaziaP(&p1))
       {
           int valor1 = desempilhaP(&p1);
           empilhaP(&p3, valor1);
           cout<<"Desempilhou p1"<<endl;
       }
       if(!vaziaP(&p2))
       {
           int valor2 = desempilhaP(&p2);
           empilhaP(&p3, valor2);
           cout<<"Desempilhou p2"<<endl;
       }

       if(vaziaP(&p1) && vaziaP(&p2))
       {
           break;
       }
   }

   mostraP(&p3);








}
