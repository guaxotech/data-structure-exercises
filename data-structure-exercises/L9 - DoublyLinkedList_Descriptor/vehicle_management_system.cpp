#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "lista_descritor-Veiculo.hpp"

// Exercise: Implements a vehicle management system using a doubly linked list with a descriptor. 
// Supports reading vehicle data from a file, displaying the list, sorting by year or model, 
// removing vehicles by license plate or manufacturer/year, and filtering vehicles by manufacturer.


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Lista lista = Lista();


   ifstream leitura("cadastro.txt");

   if(leitura.is_open())
   {
       string linha;

       while(getline(leitura, linha))
       {
           stringstream ss(linha);
           string placa, fabricante, modelo, anoString;
           int ano;

           getline(ss, placa, '#');
           getline(ss, anoString, '#');
           getline(ss, fabricante, '#');
           getline(ss, modelo, '#');

           ano = stoi(anoString);

           Veiculo veic = {placa, ano, fabricante, modelo};

           insereFimL(&lista, veic);



       }

       leitura.close();

   }
   else
   {
       cout<<"Erro ao abrir o arquivo p leitura" <<endl;
   }

   //mostraL(&lista);
   int menu;

   do{
   cout<<"\n#### MENU ####"<<endl;
   cout<<"1 - Mostrar lista de ve�culos"<<endl;
   cout<<"2 - Ordenar lista de ve�culos: o sistema solicita ao usu�rio o tipo de exibi��o da lista, se deve ser ordenada pelo ano (ordem crescente) ou pelo modelo (ordem alfab�tica)"<<endl;
   cout<<"3 - Remover um ve�culo da lista: o sistema solicita ao usu�rio a placa e, em seguida, o ve�culo que possui a placa informada � removido da lista. "<<endl;
   cout<<"4 - Remover ve�culos com base no fabricante e no ano:  o sistema solicita ao usu�rio o nome do fabricante e, em seguida, todos os ve�culos cujo o ano de fabrica��o � superior a 2000 e pertencem ao fabricante informado devem ser removidos da lista."<<endl;
   cout<<"5 - Filtrar ve�culo: o usu�rio informa o nome do fabricante e o sistema mostra a placa dos ve�culos que s�o do fabricante informado. "<<endl;
   cout<<"0 - Sair"<<endl;
   cout<<"--------------"<<endl;
   cin>>menu;

   cin.ignore();

   if(menu == 1)
    mostraL(&lista);
   else if(menu == 2)
   {
       char ordenacao;
       do{
       cout<<"Ordena��o por Ano(A-a) Ou Modelo(M-m)? "<<endl;
       cin >> ordenacao;
       }while(ordenacao != 'A' && ordenacao != 'a' && ordenacao != 'M' && ordenacao != 'm');

       if(ordenacao == 'A' || ordenacao == 'a')
       {
         mostraAnoOrdenado(&lista);
       }
       else if(ordenacao == 'M' || ordenacao == 'm')
       {
           ordenarModelosOrdemAlfabetica(&lista);
       }
   }
   else if(menu == 3)
   {
       string placa;

       cout<<"Insira a placa do ve�culo a ser buscado: " << endl;
       getline(cin, placa);

       if(removeL(&lista, placa))
          {
              cout<<"O Ve�culo de identifica��o externa " << placa << " foi removido da lista " << endl;
          }
          else
            {
                cout<<"Ve�culo n�o encontrado."<<endl;
            }
   }
   else if(menu == 4)
   {
       string fabricante;
       cout<<"Nome do fabricante: " <<endl;
       getline(cin, fabricante);

       if(removeAnoModeloL(&lista, fabricante))
       {
           cout<<"O(s) Ve�culo(s) da fabricante " << fabricante << " com ano superior a 2000 foram removido(s) da lista" << endl;
       }
       else
        cout<<"N�o foi encontrado nenhum ve�culo dessa fabricante com ano superior a 2000. "<<endl;


   }
   else if(menu == 5)
   {
       string fabricante;
       cout<<"Nome do fabricante: " <<endl;
       getline(cin, fabricante);

       filtrarVeiculos(&lista, fabricante);
   }






   }while(menu != 0);













}
