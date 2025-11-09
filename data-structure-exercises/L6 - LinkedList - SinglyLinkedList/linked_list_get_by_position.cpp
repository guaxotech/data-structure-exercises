#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;


#include "lista.hpp"

//Returns the value at a given position in the list.

int lePosicao(No **lista, int posicao)
{
    No *n = *lista;

    for(int i=0; i<=posicao; i++)
    {
        if(n == nullptr)
            return -1;
        if(i == posicao)
            return n->dado;
        else
            n = n->prox;
    }

    return -1;

}
/**/

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   No *lista = NULL;

   insereInicioL(&lista, 10);
   insereInicioL(&lista, 20);
   insereInicioL(&lista, 30);
   insereInicioL(&lista, 40);
   insereInicioL(&lista, 50);
   insereInicioL(&lista, 60);


   if(lePosicao(&lista, 30) == -1)
   {
       cout << "Posi��o n�o encontrada! " << endl;
   }
   else
    cout<<lePosicao(&lista, 30)<<endl;



    if(lePosicao(&lista, 3) == -1)
   {
       cout << "Posi��o n�o encontrada! " << endl;
   }
   else
    cout<<lePosicao(&lista, 3)<<endl;



}
