#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
float calcularMedia(Pilha *p);

// Function that calculates the arithmetic mean of the elements in a dynamic stack using pointer traversal.

void exibirMenu();
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;

    for(int i=0; i<5; i++)
    {
        int valor;
        cout<<"INSIRA O ELEMENTO " <<i+1 <<" DA PILHA: "<<endl;
        cin>>valor;
        empilhaP(&p1, valor);
    }

    cout<<"A M�DIA dos VALORES INSERIDOS �: " << calcularMedia(&p1)<<endl;



}

float calcularMedia(Pilha *p)
{
    if(vaziaP(p))
        cout<<"A Pilha EST� VAZIA! "<<endl;
    else
    {
        float soma = 0;
        NoPilha *no = p->topo;
        while(no != NULL)
        {
            soma += no->dado;
            no = no->prox;
        }
        float media = soma/5;


        return media;

    }
}
