#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

#include "pilha-dinamica.hpp"

// Program that converts decimal numbers to hexadecimal using a dynamic stack.

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   cout<<"#### DIGITE QUALQUER CARACTERE QUE N�O SEJA UM N�MERO PARA ENCERRAR O PROGRAMA ####\n" <<endl;

   int valorDecimal;



while(true)
{
   Pilha p1;

   cout<<"INSIRA UM VALOR DECIMAL: "<<endl;
   cin>>valorDecimal;

   if(cin.fail())
    break;

   int valorDecimalCopia = valorDecimal;
   int valorDecimalCopia2 = valorDecimal;

   int cont=0;

   while(valorDecimalCopia > 0)
   {
       valorDecimalCopia /= 16;
       cont++;
   }
   cout<<"O N�mero " << valorDecimal << " � divis�vel " << cont << " vezes por 16"<<endl;

   for(int i=0; i<cont; i++)
   {
       int resto = valorDecimal % 16;
       cout<<"Valor Decimal: " << valorDecimal << endl;
       cout<<"Resto: " << resto<<endl;
       empilhaP(&p1, resto);

       valorDecimal /= 16;
   }
   string numeroHexa;

   while(!vaziaP(&p1))
   {
       char valorFormatado;
       int valor = desempilhaP(&p1);

        if(valor >= 10 && valor <= 15)
        {
            if(valor == 10)
                valorFormatado = 'A';
            else if(valor == 11)
                valorFormatado = 'B';
            else if(valor == 12)
                valorFormatado = 'C';
            else if(valor == 13)
                valorFormatado = 'D';
            else if(valor == 14)
                valorFormatado = 'E';
            else if(valor == 15)
                valorFormatado = 'F';
        }
        if(valorFormatado)
            numeroHexa += valorFormatado;
        else
            numeroHexa += to_string(valor);

   }
    cout<<"-> Valor " << valorDecimalCopia2<<" (base 10) = " <<numeroHexa<<" (base 16)"<<endl;



     destroiP(&p1);


cout<<"\n";

}


}


