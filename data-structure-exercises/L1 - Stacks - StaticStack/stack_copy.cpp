#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha.hpp"

void exibirMenu();
void copiarPilha(Pilha *p1, Pilha *p2);

// Copies all elements from stack P1 to stack P2 while preserving element order.
// May use auxiliary stacks, but not arrays or direct access to the data array.
// Displays both stacks before and after the copy operation.
// Complexity: O(n)

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha *p1;
    Pilha p2;

    int tamPilha = 5;

    inicializaP(p1, tamPilha);
    inicializaP(&p2, tamPilha);

    for(int i=0; i < tamPilha; i++)
    {
        int valor;
        cout<<"Insira o VALOR " << i + 1 << ": " <<endl;
        cin>>valor;

        empilhaP(p1, valor);
    }
    cout<<"----- Pilha 1 : -----\n";
    mostraP(p1);

    copiarPilha(p1, &p2);

    cout<<"----- Pilha 2 : -----\n";

    mostraP(&p2);



}
void copiarPilha(Pilha *p1, Pilha *p2)
{
    Pilha pAux;
    inicializaP(&pAux, p1->tam);

    while(!vaziaP(p1))
    {
        int valor = desempilhaP(p1);
        empilhaP(&pAux, valor);
    }

    //mostraP(&pAux);

    while(!vaziaP(&pAux))
    {
        int valor = desempilhaP(&pAux);
        empilhaP(p2, valor);
    }



}
