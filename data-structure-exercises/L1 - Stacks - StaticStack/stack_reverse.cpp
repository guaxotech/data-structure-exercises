#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha.hpp"

// Reverses the order of elements in a stack using auxiliary stacks.
// Does not use arrays or direct element access; only push and pop operations.
// Displays the stack before and after inversion.
// Complexity: O(n)

void exibirMenu();
void invertePilha2x(Pilha *p1);
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha *p1;

    int tamPilha;

    cout<<"TAMANHO DA PILHA: "<<endl;
    cin>>tamPilha;

    inicializaP(p1, tamPilha);

    int valor;

    for(int i = 0; i < tamPilha; i++)
    {
        cout<<"Valor " << i + 1 << " da pilha: " << endl;
        cin>>valor;
        empilhaP(p1, valor);
    }

    mostraP(p1);

    invertePilha2x(p1);



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

    //cout<<" ------- Pilha ap�s duas invers�es: ------- " <<endl;
    //mostraP(&pAux2);

    //cout<<"\n -------- Jogando de volta para a pilha principal: ------- " <<endl;

    while(!vaziaP(&pAux2))
    {
        int valor;
        valor = desempilhaP(&pAux2);
        empilhaP(p1, valor);
    }

    cout<<"\n --------- Pilha Principal ap�s todas as invers�es: ------- " <<endl;
    mostraP(p1);


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
