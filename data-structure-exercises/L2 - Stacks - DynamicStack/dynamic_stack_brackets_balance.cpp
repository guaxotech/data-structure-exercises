#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;


#include "pilha-dinamica-Char.h"

// Function that checks if an expression with brackets, braces, and parentheses is balanced using a dynamic stack.

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;
   Pilha p2;

   Pilha pAux;

   bool balanceada = true;

   string expressao;

   cout<<"Insira a express�o: "<<endl;
   getline(cin, expressao);

   string expressaoFormatada;

   for(int i=0; i<expressao.size(); i++)
   {
       if(expressao[i] != ' ')
        expressaoFormatada += expressao[i];
   }

   for(int i=0; i<expressaoFormatada.size(); i++)
   {
       empilhaP(&p1, expressaoFormatada[i]);
       empilhaP(&pAux, expressaoFormatada[i]);
   }
   //mostraP(&p1);

   while(!vaziaP(&pAux))
   {
       int valor = desempilhaP(&pAux);
       empilhaP(&p2, valor);
   }
   //mostraP(&p2);


   for(int i=0; i<(expressaoFormatada.size()/2); i++)
   {
       int valor = desempilhaP(&p1);
       int valor2 = desempilhaP(&p2);

       if(valor == ']' && valor2 != '[')
       {
           balanceada = false;
           break;
       }
       else if(valor == '}' && valor2 != '{')
        {
            balanceada = false;
            break;
        }
        else if(valor == ')' && valor2 != '(')
        {
            balanceada = false;
            break;
        }
   }

   if(balanceada)
    cout<<"A Express�o \"" << expressao << "\" EST� BALANCEADA! " << endl;
   else
    cout<<"A Express�o \"" << expressao << "\" N�O EST� BALANCEADA! " << endl;













}
