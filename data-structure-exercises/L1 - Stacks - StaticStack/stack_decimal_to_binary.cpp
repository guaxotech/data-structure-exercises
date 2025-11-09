#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "pilha.hpp"

// Converts a decimal number to binary representation using a stack.
// Pushes remainders of successive divisions by 2 onto the stack, then pops to form the binary number.
// Complexity: O(log n)


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   bool achou = false, terminou = false;

   int cont = 0, numDecimal;

   cout<<"########### DIGITE 0 PARA FINALIZAR O PROGRAMA ###########"<<endl;


   while(!terminou)
   {


       cout<<"\nDIGITE UM N�MERO DECIMAL(BASE 10) PARA SER CONVERTIDO PARA BIN�RIO(BASE 2): "<<endl;
       cin>>numDecimal;

       if(numDecimal == 0)
       {
           return 0;
       }


       int numDecimalCopia = numDecimal;
       int numDecimalCopia2 = numDecimal;

        while(!achou)
       {
           if(numDecimalCopia < 2)
            achou = true;

           numDecimalCopia /= 2;
           cont++;

           if(numDecimalCopia < 2)
            achou = true;
       }

       inicializaP(&p1, cont+1);

       bool achou2 = false;

      for(int i=0; i <cont+1; i++)
      {
          empilhaP(&p1, (numDecimal % 2));
          numDecimal /= 2;

      }
    cout<<"Valor "<<numDecimalCopia2<<" Decimal(base 10) convertido para Bin�rio(base 2): "<<endl;
    if(vaziaP(&p1) == false)
    {
        cout << "------------" << endl;
        for(int i = p1.topo; i > p1.base; i--){

            cout << i << "| " << p1.dados[i]  << endl;
            cout << "------------" << endl;
        }
    }
   }

}
