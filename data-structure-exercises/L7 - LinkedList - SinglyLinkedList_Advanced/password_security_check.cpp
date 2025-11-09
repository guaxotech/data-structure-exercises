#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>


using namespace std;

#include "lista-Senhas.hpp"

string removeFinalL(No **lista)
{
    No *anterior = NULL;
    No *atual = *lista;

    if(vaziaL(lista))
        return 0;

    while(atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = NULL;

    return atual->dado;
}


/**/
No* naoSeguras(No **lista)
{
    No *senhasNaoSeguras = NULL;

    No *n = *lista;

    while(n != NULL)
    {
        bool tamanho = false;
        bool frequencia = true;

        if(n->dado.size() >= 4)
            tamanho = true;


        No *no = *lista;
        int contFrequencia = 0;

        while(no != nullptr)
        {
            if(no->dado == n->dado)
                contFrequencia++;

                if(contFrequencia > 6)
                {
                    frequencia = false;
                    break;
                }

            no = no->prox;
        }


        //cout<<"Frequencia" << frequencia << endl;
        //cout<<"Tamanho" << tamanho << endl;

        if(frequencia == false || tamanho == false)
        {
            //cout<<"entrou no if frequencia e tamanho" <<endl;
            No *nn = senhasNaoSeguras;
            int tam=0;
            while(nn != nullptr)
            {
                tam++;
                nn = nn->prox;
            }
            if(tam == 0)
                insereFinalL(&senhasNaoSeguras, n->dado);
            else
            {
                bool senhaJaFoiRegistrada = false;

                No *nnn = senhasNaoSeguras;
                while(nnn != nullptr)
                {
                    if(nnn->dado == n->dado)
                    {
                        senhaJaFoiRegistrada = true;
                        break;
                    }
                    nnn = nnn->prox;

                }
                if(!senhaJaFoiRegistrada)
                {
                    insereFinalL(&senhasNaoSeguras, n->dado);
                    //cout<<"Entrou no if senha ainda n foi registrada" << endl;
                }
            }


        }


        n = n->prox;
    }
    return senhasNaoSeguras;



}


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");


   No *lista = NULL;



   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");
   insereFinalL(&lista, "admin");


   insereFinalL(&lista, "123");
   insereFinalL(&lista, "123");
   insereFinalL(&lista, "213");
   insereFinalL(&lista, "321");
   insereFinalL(&lista, "321");

   insereFinalL(&lista, "makita1521");
   insereFinalL(&lista, "furadeira73");
   insereFinalL(&lista, "321");

   No *listaSenhasQueNaoSaoSeguras = naoSeguras(&lista);
   mostraL(&listaSenhasQueNaoSaoSeguras);


}
