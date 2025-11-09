#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.hpp"

// Inserts a new node after the first even number in the list.

void insereAposPrimeiroPar(No **lista, int valor)
{
    No *n = *lista;

    while(n != NULL && n->dado % 2 != 0)
    {
        n = n->prox;
    }

    if(n->dado == NULL)
    {
        cout << "N�o h� pares nessa lista! " << endl;
        return;
    }
    else
    {
        cout<<"Existe par, o primeiro � : " << n->dado << endl;
    }
    No *novo = new No();
    novo->dado = valor;

    //ponteiros
    novo->prox = n->prox;
    n->prox = novo;
}
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No* lista; // ou No* lista = NULL; inicializando direto.

    inicializaL(&lista);


    insereInicioL(&lista, 50);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 3);
    mostraL(&lista);

    insereAposPrimeiroPar(&lista, 200);
    mostraL(&lista);


}















