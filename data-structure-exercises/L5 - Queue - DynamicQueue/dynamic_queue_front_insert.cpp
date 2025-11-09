#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

// Exercise: Insert at Front of Dynamic Queue (furaFila)
// Description: Inserts a new node at the beginning of a dynamic queue without auxiliary structures. The new node becomes the new front by adjusting pointers only.


void exibirMenu();
void furaFila(Fila* f1, int valor);
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;

    enfileiraF(&f1, 2);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 9);

    furaFila(&f1, 200);
    mostraF(&f1);

    enfileiraF(&f1, 8);
    enfileiraF(&f1, 7);
    enfileiraF(&f1, 3);
    furaFila(&f1, 300);
    mostraF(&f1);

    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 6);
    mostraF(&f1);


    /// Teste para ver se a fun��o est� validando quando a fila est� vazia:

    /*
    furaFila(&f1, 100);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 9);
    mostraF(&f1);

    furaFila(&f1, 200);
    furaFila(&f1, 300);
    enfileiraF(&f1, 10);
    mostraF(&f1);

    destroiF(&f1);

*/


}
void furaFila(Fila* f1, int valor)
{
    NoFila *novo = new NoFila();
        //cria mais um espa�o para ser posto na fila
    novo->dado = valor;

    if(!vaziaF(f1))
    {
            // novo->prox deve apontar para o inicio da fila
                                // o endere�o de novo deve ser o inicio da fila;
    novo->prox = f1->inicio;

    f1->inicio = novo;

    }
    else
    {
        f1->inicio = novo;
        f1->fim = novo;
        novo->prox = nullptr;
    }


                                      // adiciona mais um espa�o na fila
}
