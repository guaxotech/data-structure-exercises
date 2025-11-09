#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

#include "pilha-dinamica-Documentacao.h";

// Exercise: Dispatcher Client Stacks (Dynamic)
// Description: Manages two dynamic stacks: PILHAPF (city Passo Fundo) and PILHAGERAL (other cities). Allows creating fiches, listing both stacks, reversing PILHAPF for display, computing gender stats and average age in PILHAGERAL, and finding the oldest client's plate.


string teste_sexo(char sexo)
{
    if(sexo == 'M' || sexo == 'm')
        return "Masculino";
    else
        return "Feminino";
}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   int menu = -1;

   Pilha pPF;
   Pilha pGERAL;

   while(menu != 0)
   {
       cout<<"1 - Criar ficha de atendimento: " <<endl;
       cout<<"2 - Mostrar os dados das fichas de atendimento:  " <<endl;
       cout<<"3 - Listas as fichas da pilhaPF na ordem em que elas foram preenchidas " <<endl;
       cout<<"4 - Exibir informa��es dos clientes da Pilha GERAL " <<endl;
       cout<<"5 - Mostrar a placa do ve�culo da pessoa mais velha" <<endl;
       cout<<"0 - Sair"<<endl;

       cin>>menu;

       cin.ignore();

       if(menu == 1)
       {
           Documentacao d1;

           cout<<"Nome: "<<endl;
           getline(cin, d1.nome);

           cout<<"Idade: "<<endl;
           cin>>d1.idade;


           do{
           cout<<"Sexo: (M | F)" <<endl;
           cin>>d1.sexo;
           }while(d1.sexo != 'M' && d1.sexo != 'm' && d1.sexo != 'F' && d1.sexo != 'f');

           cin.ignore();

           cout<<"Cidade: " <<endl;
           getline(cin, d1.cidade);

           cout<<"Placa do ve�culo: "<<endl;
           cin>>d1.placaVeiculo;

           string copiaCidade = d1.cidade;

           for( char &c : d1.cidade)          // &c para que n�o somente a c�pia seja modificada
           {
               c = toupper(c);
           }

           if(d1.cidade.find("PASSO FUNDO") != string::npos || d1.cidade.find("PF") != string::npos)
           {
               d1.cidade = copiaCidade;
               empilhaP(&pPF, d1);
           }
           else
           {
               d1.cidade = copiaCidade;
               empilhaP(&pGERAL, d1);
           }

       }
       else if(menu == 2)
       {
           if(!vaziaP(&pPF))
           {
               cout<<"--> PILHA PF: \n" <<endl;
               //cout<<"-----------------------------------------"<<endl;
               NoPilha *no = pPF.topo;
               while(no != NULL)
               {
                   cout <<"Nome: " << no->dado.nome << endl;
                   cout <<"Idade: " << no->dado.idade << endl;
                   cout <<"Sexo: " << teste_sexo(no->dado.sexo) << endl;
                   cout <<"Cidade: " << no->dado.cidade << endl;
                   cout <<"Placa do Ve�culo: " << no->dado.placaVeiculo << endl;
                   cout << "========================================\n" << endl;

                   no = no->prox;
               }
           }

           if(!vaziaP(&pGERAL))
           {
               cout<<"--> PILHA GERAL: \n" <<endl;
               //cout<<"-----------------------------------------"<<endl;
               NoPilha *no = pGERAL.topo;
               while(no != NULL)
               {
                   cout <<"Nome: " << no->dado.nome << endl;
                   cout <<"Idade: " << no->dado.idade << endl;
                   cout <<"Sexo: " << teste_sexo(no->dado.sexo) << endl;
                   cout <<"Cidade: " << no->dado.cidade << endl;
                   cout <<"Placa do Ve�culo: " << no->dado.placaVeiculo << endl;
                   cout << "========================================\n" << endl;

                   no = no->prox;
               }
           }
       }
       else if(menu == 3)
       {
           int cont=0;
           Pilha pAux;

           if(!vaziaP(&pPF))
           {


           cout << "\n====== DADOS CLIENTES DA PILHA PF CONFORME ORDEM DE PREENCHIMENTO ======\n" << endl;
           while(!vaziaP(&pPF))
           {
               Documentacao documento = desempilhaP(&pPF);
               empilhaP(&pAux, documento);
           }
           while(!vaziaP(&pAux))
           {
               cont++;
               Documentacao documento = desempilhaP(&pAux);
               cout <<"Nome: " << documento.nome << endl;
               cout <<"Idade: " << documento.idade << endl;
               cout <<"Sexo: " << teste_sexo(documento.sexo) << "               ["<<cont<<"]" << endl;
               cout <<"Cidade: " << documento.cidade << endl;
               cout <<"Placa do Ve�culo: " << documento.placaVeiculo << endl;
               cout << "========================================\n" << endl;
               empilhaP(&pPF, documento);
           }

           }
           else
            cout<<"\n**A Pilha PF est� VAZIA! **\n"<<endl;
       }
       else if(menu == 4)
       {
           if(!vaziaP(&pGERAL))
           {
               int contFeminino = 0;
               int contMasculino = 0;
               float somaIdades = 0;

               NoPilha *no = pGERAL.topo;
               while(no != NULL)
               {
                   if(no->dado.sexo == 'F' || no->dado.sexo == 'f')
                   {
                       contFeminino++;
                   }
                   else
                    contMasculino++;

                   somaIdades += (no->dado.idade);

                   no = no->prox;
               }
               cout << "\n====== DADOS CLIENTES DA PILHA GERAL ======" << endl;
               cout<<"N�mero de clientes do Sexo Masculino: " << contMasculino << endl;
               cout<<"N�mero de clientes do Sexo Feminino: " << contFeminino << endl;
               cout<<fixed<<setprecision(2);
               cout<<"M�dia Aritm�tica da Idade dos Clientes: " << (somaIdades / (contMasculino + contFeminino) ) << " anos " <<endl;
               cout << "========================================\n" << endl;
           }
       }
       else if(menu == 5)
       {
           Pilha pAux;

           if(!vaziaP(&pPF))
           {
            NoPilha *no = pPF.topo;
            while(no != NULL)
            {
                   Documentacao documento = no->dado;
                   empilhaP(&pAux, documento);

                   no = no->prox;
            }
           }

           if(!vaziaP(&pGERAL))
           {
            NoPilha *no = pGERAL.topo;
            while(no != NULL)
            {
                   Documentacao documento = no->dado;
                   empilhaP(&pAux, documento);

                   no = no->prox;
            }
           }

           int maiorIdade = INT_MIN;
           string nomePessoa;
           string placaPessoa;
           if(!vaziaP(&pGERAL) || !vaziaP(&pPF))
           {
            NoPilha *no = pAux.topo;
            while(no != NULL)
            {
                   if(no->dado.idade > maiorIdade)
                   {
                       maiorIdade = no->dado.idade;
                       nomePessoa = no->dado.nome;
                       placaPessoa = no->dado.placaVeiculo;
                   }

                   no = no->prox;
            }

            cout << "\n====== DADOS DA PESSOA MAIS VELHA ======" << endl;
            cout << "Nome:  " << nomePessoa << endl;
            cout << "Idade: " << maiorIdade << " anos" << endl;
            cout << "Placa: " << placaPessoa << endl;
            cout << "========================================\n" << endl;
           }
           else
           {
               cout<<"\n**Ambas as pilhas est�o vazias! **\n"<<endl;
           }


       }
   }










}
