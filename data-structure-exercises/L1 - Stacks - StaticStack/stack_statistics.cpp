#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#include "pilha.hpp"

// Calculates the minimum, maximum, and average values stored in a stack.
// Results are returned by reference using pointer parameters.
// Handles empty stacks by returning 0 for all values.
// Complexity: O(n)


void exibirMenu();
void estatisticaP(Pilha *p, int *menor, int *maior, float *media);
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Pilha *p1;

    inicializaP(p1, 10);

    for(int i=0; i<10; i++)
    {
        int valor;
        cout<<"Digite o valor " << i + 1 << " da pilha: " << endl;
        cin >> valor;
        empilhaP(p1, valor);
    }
    int *menor = new int(INT_MAX);
    int *maior = new int(INT_MIN);
    float *media = new float(0);

    estatisticaP(p1, menor, maior, media);

    cout<<"Menor valor: " << *menor << "\nMaior valor: " << *maior << "\nM�dia Aritm�tica: " << *media << endl;

    delete menor;
    delete maior;
    delete media;


}
void estatisticaP(Pilha *p, int *menor, int *maior, float *media)
{
    float soma = 0;
    if(vaziaP(p))
    {
        *menor = 0;
        *maior = 0;
        *media = 0;
    }
    else
    {
        *menor = p->dados[p->topo];
        *maior = p->dados[p->topo];

        while(!vaziaP(p))
        {
            int valor;
            valor = desempilhaP(p);
            soma += valor;
            if(valor < *menor)
                *menor = valor;
            else if(valor > *maior)
                *maior = valor;
        }

        *media = soma/10;
    }

}
