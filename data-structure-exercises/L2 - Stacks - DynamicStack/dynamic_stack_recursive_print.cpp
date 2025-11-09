#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha-dinamica.hpp"

// Recursive function that prints the elements of a stack in reverse order (top to bottom).

void exibirInvertido(Pilha *p1);

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   empilhaP(&p1, 38);
   empilhaP(&p1, 82);
   empilhaP(&p1, 99);
   empilhaP(&p1, 49);
   empilhaP(&p1, 64);

   cout<<"Elementos da Pilha exibidos Inversamente: "<<endl;

   exibirInvertido(&p1);


}
void exibirInvertido(Pilha *p1)
{
    if(!vaziaP(p1))
    {
    int valor = desempilhaP(p1);
    cout<<"-> " << valor<<endl;
    exibirInvertido(p1);
    }
}
