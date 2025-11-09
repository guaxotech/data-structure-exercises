#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

// Inserts a new node before the first even number in the list.

void insereAntesPrimeiroPar(No **lista, int valor)
{
    No* anterior = NULL;
    No *atual = *lista;

    while(atual != NULL && atual->dado % 2 != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }
    //cout<<"Anterior: " << anterior->dado << endl;
    //cout<<"Atual: " << atual->dado << endl;

    if(atual == NULL)
    {
        cout<< "N�o h� nenhum par na lista! " << endl;
        return;
    }

    No* novo = new No();
    novo->dado = valor;

    if(anterior == NULL)
    {
        novo->prox = atual;
        *lista = novo;
    }
    else
    {
    novo->prox = atual;
    anterior->prox = novo;
    }




}


void exibirMenu();
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No* lista; // ou No* lista = NULL; inicializando direto.

    inicializaL(&lista);


    insereInicioL(&lista, 50);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 30);
    mostraL(&lista);

    insereAntesPrimeiroPar(&lista, 200);
    mostraL(&lista);
    insereAntesPrimeiroPar(&lista, 5);
    mostraL(&lista);

}
