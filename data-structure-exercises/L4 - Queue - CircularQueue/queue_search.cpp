#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "filacircular.hpp"

// Implements two search functions in a queue: one using an auxiliary queue and another without using any auxiliary data structure.

void exibirMenu();
void buscarValorComAuxiliar(Fila *f);
void buscarValorSemAuxiliar(Fila *f);

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;

    inicializaF(&f1, 5);

    enfileiraF(&f1, 20);
    enfileiraF(&f1, 400);
    enfileiraF(&f1, 1600);
    enfileiraF(&f1, 3200);
    enfileiraF(&f1, 25);

    //buscarValorComAuxiliar(&f1);
    buscarValorSemAuxiliar(&f1);

}
void buscarValorComAuxiliar(Fila *f)
{
    bool achou = false;
    int valor;
    cout<<"INSIRA O VALOR QUE SER� PROCURADO NA FILA: "<<endl;
    cin>>valor;

    Fila fAux;

    inicializaF(&fAux, f->tam);

    while(!vaziaF(f))
    {
        int num = desenfileiraF(f);
        if(num == valor)
        {
            achou = true;
            break;
        }
        enfileiraF(&fAux, num);
    }
    if(achou)
        cout<<"O Valor " << valor << " FOI ENCONTRADO na fila! " << endl;
    else
        cout<<"O Valor " << valor << " N�O FOI ENCONTRADO na fila! " << endl;

        while(!vaziaF(&fAux))
        {
            int num = desenfileiraF(&fAux);
            enfileiraF(f, num);
        }
        //mostraF(f);
}
void buscarValorSemAuxiliar(Fila *f)
{
    bool achou = false;
    int valor;
    cout<<"Insira o valor que ser� procurado na fila: "<<endl;
    cin>>valor;
    for(int i=0; i<f->total; i++)
    {
        int val = f->dados[i];
        if(valor == val)
        {
            achou = true;
            break;
        }
    }
    if(achou)
        cout<<"O Valor " << valor << " FOI ENCONTRADO na fila! " << endl;
    else
        cout<<"O Valor " << valor << " N�O FOI ENCONTRADO na fila! " << endl;
}
