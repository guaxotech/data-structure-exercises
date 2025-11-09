#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha-dinamica-Cadastro.h"

// Program that manages client registrations in a bank system using a dynamic stack ordered alphabetically by name.

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");


    Pilha p1;


    int codigoCliente = 0;
    string nomeCliente;
    int idade, menu=-1;
    float saldo;

    while(menu != 0)
    {
        cout<<"\t--#1--- CADASTRAR CLIENTES -----\t"<<endl;
        cout<<"\t--#2---  MOSTRAR CLIENTES  -----\t"<<endl;
        cout<<"\t--#0---  SAIR DO SISTEMA   -----\t"<<endl;
        cout<<"\n";
        cin>>menu;

        cin.ignore();

    if(menu == 1)
    {
    cout<<"INSIRA O NOME DO CLIENTE: "<<endl;
    getline(cin, nomeCliente);

    codigoCliente++;

    cout<<"IDADE: "<<endl;
    cin>>idade;
    cin.ignore();

    cout<<"SALDO: "<<endl;
    cin>>saldo;
    cin.ignore();

    Cadastro c1 = {codigoCliente, nomeCliente, idade, saldo};

    if(!vaziaP(&p1))
    {
        Pilha pAux;

        bool achou = false;

        while(!achou)
        {

        Cadastro valor = desempilhaP(&p1);

        if(valor.nome > nomeCliente)            /// Se o nome armazenado na ultima pos. da pilha � "maior" que o nome que ser� armazenado
        {
            empilhaP(&p1, valor);
            empilhaP(&p1, c1);
            achou = true;
        }
        else
        {
            if(vaziaP(&p1))
            {
               empilhaP(&p1, c1);
               empilhaP(&p1, valor);
            }
            else
                empilhaP(&pAux, valor);
        }

        }

        while(!vaziaP(&pAux))
        {
            Cadastro val = desempilhaP(&pAux);
            empilhaP(&p1, val);
        }

        destroiP(&pAux);
    }
    else
    {
        empilhaP(&p1, c1);
    }

    }
    else if(menu == 2)
    {
        mostraP(&p1);

    }


    }

















}

