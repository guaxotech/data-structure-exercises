#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha.hpp"

void exibirMenu();
bool iguais(Pilha *p1, Pilha *p2);

// Provides two operations using stacks:
// 1. Checks whether two stacks are equal (same elements and same order).
// 2. Counts how many elements in a stack have even values.
// Uses only stack operations (push/pop) with an auxiliary stack.
// Complexity: O(n)


main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Pilha p2;

    int tamPilha = 5;

    inicializaP(&p1, tamPilha);
    inicializaP(&p2, tamPilha);

    for(int i=0; i<tamPilha; i++)
    {
        int valor;
        cout<<"Elemento " << i + 1 << " da PILHA 1: " << endl;
        cin>> valor;
        empilhaP(&p1, valor);
    }

    for(int i=0; i < tamPilha; i++)
    {
        int valor;
        cout<<"Elemento " << i + 1 << " da PILHA 2: " << endl;
        cin>> valor;
        empilhaP(&p2, valor);
    }
    if(iguais(&p1, &p2))
        cout<<"As Pilhas que Voc� digitou S�O IGUAIS! " <<endl;
    else
        cout<<"As Pilhas que Voc� digitou S�O DIFERENTES! " <<endl;



}
bool iguais(Pilha *p1, Pilha *p2)
{
    Pilha pAux;
    inicializaP(&pAux, p1->tam);

    while(!vaziaP(p2))
    {
        int valor;
        valor = desempilhaP(p2);
        empilhaP(&pAux, valor);

    }
    while(!vaziaP(&pAux))
    {
        int valor;
        valor = desempilhaP(&pAux);
        empilhaP(p2, valor);
    }
    //cout<<"P1: " <<endl;
    mostraP(p1);
    //cout<<"P2: " <<endl;
    mostraP(p2);

    bool iguais = true;

    while( !vaziaP(p1) && !vaziaP(p2) )
    {
        int valor1 = desempilhaP(p1);
        cout<<"v1 : " <<valor1<<endl;
        int valor2 = desempilhaP(p2);
        cout<<"v2 : " <<valor1<<endl;

        if(valor1 == valor2)
        {
            iguais = true;
        }
        else
        {
            iguais = false;
            return false;
        }

    }

    return true;









    /*while( (!vaziaP(p1)) && (!vaziaP(p2)) )
    {
        valor1 = desempilhaP(p1)
    }*/
}
