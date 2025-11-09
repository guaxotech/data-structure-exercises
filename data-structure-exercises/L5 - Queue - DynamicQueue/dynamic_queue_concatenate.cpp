#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

// Exercise: Concatenate Two Dynamic Queues
// Description: Implements functions to concatenate two dynamic queues, returning a new queue or filling an output queue passed by reference.
// Example prototypes: Queue concatQueues(Queue* q1, Queue* q2); void concatQueues(Queue* q1, Queue* q2, Queue* qOut);


void exibirMenu();
void concatenaF(Fila *f1, Fila *f2, Fila *fConcatenada);

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Fila f2;
    Fila fConcatenada;

    enfileiraF(&f1, 10);
    enfileiraF(&f1, 20);
    enfileiraF(&f1, 30);
    enfileiraF(&f1, 40);
    enfileiraF(&f1, 50);

    mostraF(&f1);
    cout<<"-----------------------"<<endl;
    enfileiraF(&f2, 60);
    enfileiraF(&f2, 70);
    enfileiraF(&f2, 80);
    enfileiraF(&f2, 90);
    enfileiraF(&f2, 100);
    mostraF(&f2);

    concatenaF(&f1,&f2,&fConcatenada);

    cout<<"-----------------------"<<endl;
    mostraF(&fConcatenada);





}
void concatenaF(Fila *f1, Fila *f2, Fila *fConcatenada)
{
    while(!vaziaF(f1))
    {
        int valor = desenfileiraF(f1);
        enfileiraF(fConcatenada, valor);
    }
    while(!vaziaF(f2))
    {
        int valor = desenfileiraF(f2);
        enfileiraF(fConcatenada, valor);
    }

}
