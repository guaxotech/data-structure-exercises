#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha-dinamica.hpp"

// Program that sorts a sequence of integers in ascending order using two dynamic stacks (ORD and AUX)

/**/

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   int valor = -1;

      Pilha pOrd;

      Pilha pAux;



   while(valor != 0)
{

   bool achou = false;

   cout<<"#####-Digite 0 para encerrar o looping-#####\n Insira um valor na pilha: "<<endl;
   cin>>valor;

   if(valor == 0)
    break;

   if(vaziaP(&pOrd))
   {
       empilhaP(&pOrd, valor);
   }
   else
   {
       while(!achou)
       {
           int valorTeste = desempilhaP(&pOrd);

           if(valor > valorTeste)
           {
               empilhaP(&pOrd, valorTeste);
               empilhaP(&pOrd, valor);
               achou = true;
           }
           else
           {
               empilhaP(&pAux, valorTeste);
           }
       }
         while(!vaziaP(&pAux))
           {
               int val = desempilhaP(&pAux);
               empilhaP(&pOrd, val);
           }



   }

}


   mostraP(&pOrd);

}





