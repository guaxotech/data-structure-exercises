#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilhaChar.h"

// Verifies if a mathematical expression has balanced parentheses using a stack.
// Example of balanced: (A+B), ((A+B)+(C+D))
// Example of unbalanced: ((A+B), )A+B(, (A+B)) – (C + D)
// Complexity: O(n)

void invertePilha2x(Pilha *p1);

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   string expressao;

   Pilha p1;

   cout<<"Insira a Express�o: "<<endl;
   getline(cin, expressao);

   inicializaP(&p1, expressao.size());

   Pilha p2;

   inicializaP(&p2, expressao.size());

   for(int i=0; i<expressao.size(); i++)
   {
       char valor = expressao[i];
       empilhaP(&p1, valor);
   }

   for(int i=0; i<expressao.size(); i++)
   {
       char valor = expressao[i];
       empilhaP(&p2, valor);
   }

   invertePilha2x(&p2);

   for(int i=0; i < (expressao.size()/2); i++)
   {
       char valor = desempilhaP(&p1);
       char valor2 = desempilhaP(&p2);

       if( valor == ')' && valor2 != '(' )
        cout<<"Isso est� errado"<<endl;
   }

   mostraP(&p1);

   mostraP(&p2);

















}
void invertePilha2x(Pilha *p1)
{
    Pilha pAux;
    inicializaP(&pAux, p1->tam);

    while(!vaziaP(p1))
    {
        int valor;
        valor = desempilhaP(p1);
        empilhaP(&pAux, valor);

    }

    //mostraP(&pAux);

    Pilha pAux2;
    inicializaP(&pAux2, p1->tam);

    while(!vaziaP(&pAux))
    {
        int valor;
        valor = desempilhaP(&pAux);
        empilhaP(&pAux2, valor);
    }

    //cout<<" ------- Pilha ap s duas invers es: ------- " <<endl;
    //mostraP(&pAux2);

    //cout<<"\n -------- Jogando de volta para a pilha principal: ------- " <<endl;

    while(!vaziaP(&pAux2))
    {
        int valor;
        valor = desempilhaP(&pAux2);
        empilhaP(p1, valor);
    }

    //cout<<"\n --------- Pilha Principal ap s todas as invers es: ------- " <<endl;
    //mostraP(p1);


    /*Pilha *pAux2;
    inicializaP(pAux, pAux->tam);

    for(int i=0; i <(p1->tam); i++)
    {
        int valor;
        valor = desempilhaP(pAux);
        empilhaP(pAux2, valor);
    }
    for(int i=0; i < (p1->tam); i++)
        cout<< pAux2->dados[i] << ", \n";*/
}

