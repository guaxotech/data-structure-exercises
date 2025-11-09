#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

#include "pilha-dinamica.hpp"

// Program that reads commands from a file and performs stack operations (insert, remove, search, display, remove all).

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   ofstream escrita("entrada.txt", ios :: out);

    if(escrita.is_open())
    {
        escrita << "MOSTRAR\n";
        escrita << "REMOVER\n";
        escrita << "CONSULTAR 2\n";
        escrita << "INSERIR 1\n";
        escrita << "INSERIR 2\n";
        escrita << "INSERIR 3\n";
        escrita << "INSERIR 4\n";
        escrita << "INSERIR 5\n";
        escrita << "MOSTRAR\n";
        escrita << "REMOVER\n";
        escrita << "MOSTRAR\n";
        escrita << "CONSULTAR 10\n";
        escrita << "CONSULTAR 2\n";
        escrita << "REMOVERTODOS\n";
        escrita << "MOSTRAR\n";
    }

   escrita.close();


   ifstream leitura("entrada.txt", ios::in);


   string linha;

       while(getline(leitura, linha))
       {
           string operacao;
           int num;

           leitura >> operacao;

           //cout<<"operacao"<<operacao<<endl;

           if(operacao != "MOSTRAR" && operacao != "REMOVER" && operacao != "REMOVERTODOS")
           {
               leitura >> num;
               //cout<<"num"<<num<<endl;
           }

        if(operacao  == "INSERIR")
       {
           empilhaP(&p1, num);
           cout<<"O valor " << num << " foi inserido na pilha."<<endl;

       }
       else if(operacao == "REMOVER")
       {
           if(!vaziaP(&p1))
           {
           int valor = desempilhaP(&p1);
           cout<<"O elemento "<<valor<<" foi removido da pilha."<<endl;
           }
           else
            cout<<"PILHA VAZIA"<<endl;
       }
       else if(operacao == "MOSTRAR")
       {
           Pilha pAux;
           if(!vaziaP(&p1))
           {
               while(!vaziaP(&p1))
               {
                   int valor = desempilhaP(&p1);
                   cout<<valor<<", ";
                   empilhaP(&pAux, valor);
               }
               while(!vaziaP((&pAux)))
               {
                   int valor = desempilhaP(&pAux);
                   empilhaP(&p1, valor);
               }
               cout<<"\n";
           }
           else
            cout<<"PILHA VAZIA"<<endl;
       }
       else if(operacao == "CONSULTAR")
       {
               if(buscaP(&p1, num))
               {
                   cout<<"O valor "<<num <<" est� armazenado na pilha."<<endl;
               }
               else
                cout<<"O valor " << num << " n�o est� armazenado na pilha. "<<endl;
       }
       else if(operacao == "REMOVERTODOS")
       {
           while(!vaziaP(&p1))
           {
               desempilhaP(&p1);
           }
           cout<<"Todos os elementos removidos."<<endl;

       }
       //cout<<"\n";



   }

   leitura.close();










}

