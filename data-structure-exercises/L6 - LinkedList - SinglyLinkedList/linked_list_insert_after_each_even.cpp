#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

//Inserts a new node after every even number in the list.

void insereAposCadaPar(No **lista, int valor)
{
    No *n = *lista;
    while(n != NULL)
    {
        if(n->dado % 2 == 0)
        {
            No *novo = new No();
            novo->dado = valor;

            novo->prox = n->prox;
            n->prox = novo;

            n=n->prox;
        }
        n = n->prox;
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
    insereInicioL(&lista, 10);
    mostraL(&lista);

    insereAposCadaPar(&lista, 200);
    mostraL(&lista);
}
