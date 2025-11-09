#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "pilha-dinamica-Char.h"

// Program that reverses the letters of each word in a sentence using a dynamic stack (no arrays allowed).

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int cont=0, x=0, proxPosicao;
    string frase;

    cout<<"Insira a Frase: "<<endl;
    getline(cin, frase);

    string fraseCopia = frase;

    for(int i=0; i<frase.size(); i++)  /// Ver quantas palavras h� na frase(por meio dos espa�os em branco) e achar o primeiro espa�o em branco;
    {
        char caractere = frase[i];
        if(caractere == ' ')
            cont++;
    }

    string fraseFormatada;

    //cout<<cont<<endl;

    while(x <= cont)
    {
     Pilha p1;


     if(x == 0)
     {
    for(int i=0; i<frase.size(); i++)
    {
        char caractere = frase[i];
        if(frase[i] == ' ')
        {
            proxPosicao = i+1;
            //cout<<"pr�x  Posi��o: "<<proxPosicao<<endl;
            break;
        }
        empilhaP(&p1, caractere);
    }
     }
     else
     {
         for(int i=proxPosicao; i<frase.size(); i++)
    {
        char caractere = frase[i];
        if(caractere == ' ')
        {
            proxPosicao = i+1;
            break;
        }
        empilhaP(&p1, caractere);
    }
     }

     //mostraPP(&p1);

    if(x == 0)
    {
    for(int i=0; i<frase.size(); i++)
    {
        char caractere = desempilhaP(&p1);
        fraseFormatada += caractere;

        if(i == (frase.size() - 1))
            fraseFormatada += ' ';
    }
    }
    else
    {
        for(int i=0; i<frase.size(); i++)
         {
        char caractere = desempilhaP(&p1);
        fraseFormatada += caractere;

        if(i == (frase.size() - 1))
            fraseFormatada += ' ';
         }
    }

    destroiP(&p1);
    x++;

    }
    //cout<<x<<endl;

    cout<<"Frase Inicial: "<<fraseCopia<<endl;
    cout<<"Frase Formatada: "<<fraseFormatada<<endl;




}

