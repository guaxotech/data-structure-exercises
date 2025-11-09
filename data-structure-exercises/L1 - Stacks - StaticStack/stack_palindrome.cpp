#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilhaChar.h"

void inverterP(Pilha *p);
void copiarP(Pilha *p, Pilha *p2);

// Checks whether an input text is a palindrome using a stack.
// Ignores spaces, punctuation, and special characters (only letters are considered).
// Uses only stack operations (push/pop) without direct array access.
// Complexity: O(n)

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");

    Pilha p1;
    string texto;

    cout<<"Insira a frase: "<<endl;
    getline(cin, texto);

    for(int i=0; i<texto.size(); i++)
    {
        texto[i]=tolower(texto[i]);
    }

    //cout<<texto.size()<<endl;

    int cont=0;

    string textoFormatado;

    for(int i=0; i<texto.size(); i++)
    {
        if(isalpha(texto[i]))
        {
            textoFormatado += texto[i];
            cont++;
        }
    }
    //cout<<"Texto Formatado: "<<textoFormatado<<endl;
    //cout<<"Cont: "<<cont<<endl;


    inicializaP(&p1, cont);

    for(int i=0; i<textoFormatado.size(); i++)
    {

        char caractere = textoFormatado[i];

        if(isalpha(caractere))
        {
            empilhaP(&p1, caractere);
        }

    }
    Pilha p2;
    inicializaP(&p2, p1.tam);


    copiarP(&p1, &p2);

    inverterP(&p2);

    //mostraP(&p1);

    //cout<<"Pilha 2: "<<endl;
    //mostraP(&p2);

    bool achouDiferente = false;

    for(int i=0; i<p1.tam; i++)
    {
        char valor1 = desempilhaP(&p1);
        char valor2 = desempilhaP(&p2);

        if(valor1 == valor2)
        {
            achouDiferente = false;
        }
        else
        {
            achouDiferente = true;
            break;
        }
    }
    if(achouDiferente)
        cout<<"\nEssa frase N�O � considerada UM PAL�NDROMO! "<<endl;
    else
        cout<<"\nEssa frase � UM PAL�NDROMO! "<<endl;



}
void copiarP(Pilha *p, Pilha *p2)
{
    Pilha pAux;
    inicializaP(&pAux, p->tam);

    Pilha pTemp;
    inicializaP(&pTemp, p->tam);

    for(int i=0; i<p->tam; i++)
     {
       char valor = desempilhaP(p);    /// Desempilhar a pilha e jogar para pAux
       empilhaP(&pAux, valor);
       empilhaP(&pTemp, valor);
     }

     for(int i=0; i<pAux.tam; i++)
     {
         char valor = desempilhaP(&pAux);      /// Desempilhar pAux e jogar para p2
         empilhaP(p2, valor);
     }

     for(int i=0; i<p2->tam; i++)
     {
         char valor = desempilhaP(&pTemp);      /// Desempilhar pTemp e jogar para p (Assim, ele continua com seus valores originais)
         empilhaP(p, valor);
     }
}
void inverterP(Pilha *p)
{
    Pilha pAux;
    inicializaP(&pAux, p->tam);

   for(int i=0; i<p->tam; i++)
   {
       char valor = desempilhaP(p);    /// Desempilhar a pilha e jogar para pAux
       empilhaP(&pAux, valor);
   }

   Pilha pAux2;
   inicializaP(&pAux2, pAux.tam);

   for(int i=0; i<p->tam; i++)
   {
       char valor = desempilhaP(&pAux);    /// Desempilhar o pAux e jogar para pAux2
       empilhaP(&pAux2, valor);
   }

   for(int i=0; i<pAux.tam; i++)
   {
       char valor = desempilhaP(&pAux2);    /// Desempilhar o pAux2 e jogar para p
       empilhaP(p, valor);
   }

}
bool verificaPalindromo(Pilha *p1, Pilha *p2)
{

}
