#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "lista_dupla-String.h"

// Exercise: Reads a sequence of directions (up, down, left, right) from a text file 
// and stores them in a doubly linked list. 
// Displays the path taken (forward direction) and the path to return (reverse direction) 
// by traversing the list in both orders.


void exibirCaminhoVolta(Lista *lista)
{
    No *n = lista->fim;

    cout<<"\nVOLTA: " << endl;

    while(n != nullptr)
    {
        if(n->dado == "cima")
        {
            cout<<"baixo, ";
        }
        else if(n->dado == "baixo")
        {
            cout<<"cima, ";
        }
        else if(n->dado == "direita")
        {
            cout<<"esquerda, ";
        }
        else if(n->dado == "esquerda")
        {
            cout<<"direita, ";
        }

        n = n->ant;
    }
}

void exibirCaminhoIda(Lista *lista)
{
    No *n = lista->inicio;

    cout<<"IDA: " << endl;

    while(n != nullptr)
    {
        cout << n->dado << ", ";

        n = n->prox;
    }
}

/**/

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   ifstream leitura("labirinto.txt");

   if (!leitura.is_open())
   {
       cout<< "Erro ao abrir o arquivo." << endl;
   }

   Lista lista = Lista();

   string caminho;

   while(getline(leitura, caminho, ',')) {
        insereFimL(&lista, caminho);
   }



   leitura.close();

   exibirCaminhoIda(&lista);


   exibirCaminhoVolta(&lista);
















}
