#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "filacircularAvioes.hpp"

void exibirMenu();
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Fila f1;

    inicializaF(&f1, 5);

    int menu=-1;

    while(menu != 0)
{
    cout<<" 1 - Mostrar Nº de Aviões à espera para decolagem "<<endl;
    cout<<" 2 - Entrada de um Novo Avião na Pista (incluir na fila) "<<endl;
    cout<<" 3 - Decolagem de um Avião (remover da fila) "<<endl;
    cout<<" 4 - Listar todos os aviões à espera para decolagem (mostrar fila) "<<endl;
    cout<<" 5 - Listar as características do próximo avião a decolar (peek) " <<endl;
    cout<<" 0 - Sair do Menu" <<endl;
    cin>>menu;

    cin.ignore();

    if(menu == 1)
    {
        cout<<"--------------------------------------"<<endl;
        cout<<"Número de Aviões em espera para decolagem: "<<endl;
        cout<<"\t"<<f1.total<<endl;
        cout<<"--------------------------------------"<<endl;
    }
    else if(menu == 2)
    {
        string nome;
        int codigo;
        float peso;
        int capacidade;

        if(!cheiaF(&f1))
        {
            cout<<"Nome: "<<endl;
            getline(cin, nome);


            cout<<"Código: "<<endl;
            cin>>codigo;

            cout<<"Peso: "<<endl;
            cin>>peso;

            cout<<"Capacidade: "<<endl;
            cin>>capacidade;

            Avioes a1 = {nome, codigo, peso, capacidade};

            enfileiraF(&f1, a1);
        }
        else
            cout<<"A PISTA ESTÁ CHEIA! "<<endl;
    }
    else if(menu == 3)
    {
        if(!vaziaF(&f1))
        {
            Avioes valor = desenfileiraF(&f1);
            cout<<valor.nome<<", código : " <<valor.codigo <<" acabou de decolar! " <<endl;
        }
        else
            cout<<"Não há nenhum Avião na pista esperando para decolar! "<<endl;
    }
    else if(menu == 4)
    {
        if(!vaziaF(&f1))
        {
            for(int i=0; i<f1.total; i++)
            {
                cout<<"--------------------------------------"<<endl;
                cout<<"["<<i + 1 <<"]" <<"\nAeronave: " << f1.dados[i].nome << "\nCódigo: " << f1.dados[i].codigo << "\nPeso: " << f1.dados[i].peso <<" Toneladas" << "\nCapacidade: " << f1.dados[i].capacidade <<" Passageiros " << endl;
                cout<<"--------------------------------------"<<endl;
            }
        }
    }
    else if(menu == 5)
    {
        Avioes prox = espiaF(&f1);
        cout<<"Características do próximo avião a decolar: " <<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Aeronave: " <<prox.nome << "\nCódigo: " << prox.codigo << "\nPeso: " << prox.peso <<" Toneladas"<< "\nCapacidade: " << prox.capacidade <<" Passageiros" << endl;
        cout<<"--------------------------------------"<<endl;
    }







}
}
