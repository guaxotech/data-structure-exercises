#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

#include "caixa.h"

using namespace std;

// Manages loading and unloading of boxes in a truck using a stack.
// Each box has a code and a weight (struct Caixa).
// Supports operations: define size, load (push), unload (pop), show contents, and exit.
// Stack is implemented with dynamic memory for struct Caixa.
// Complexity: O(1) for push/pop operations.


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");


   cout<<"########## MENU ##########"<<endl;
   cout<<"1 - Definir quantidade de caixas "<<endl;
   cout<<"2 - Carregar caixa "<<endl;
   cout<<"3 - Descarregar caixa "<<endl;
   cout<<"4 - Mostrar carga" <<endl;
   cout<<"0 - Sair do Programa "<<endl;

   Pilha *p1;

   int i = 1;

   if(menu == 1)
   {
       int qtdCaixas;

       cout<<"Quantidade de caixas: "<<endl;
       cin>>qtdCaixas;

       inicializaP(p1, qtdCaixas);
   }
   else if(menu == 2)
   {
       Caixa *c;
       *c.codigo = i;
       cout<<"Peso da caixa: "<<endl;
       cin>>*c.peso;

       empilharP(p1, c)
   }








}
