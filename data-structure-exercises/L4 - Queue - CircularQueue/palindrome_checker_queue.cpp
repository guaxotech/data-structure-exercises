#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

#include "filacircular-Char.h"
#include "pilha-dinamica-Char.h"

/**/
string formatarMinusculo(string frase);

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   string frase;
   bool palindromo = true;

   cout<<"Insira uma palavra: "<<endl;
   getline(cin, frase);

   string fraseFormatada = formatarMinusculo(frase);

   Pilha p1;

   Fila f1;

   inicializaF(&f1, frase.length());

   for(int i=0; i<frase.length(); i++)
   {
       empilhaP(&p1, fraseFormatada[i]);
   }
   for(int i=0; i<frase.length(); i++)
   {
       enfileiraF(&f1, fraseFormatada[i]);
   }

   for(int i=0; i<frase.length(); i++)
   {
       char valor = desempilhaP(&p1);
       char valor2 = desenfileiraF(&f1);

       if(valor != valor2)
       {
           palindromo = false;
           break;
       }
   }
   if(palindromo)
    cout<<"A palavra \"" << frase << "\" é um palíndromo! " << endl;
   else
    cout<<"A palavra \"" << frase << "\" não é um palíndromo! " << endl;


}
string formatarMinusculo(string frase)
{
    for(int i=0; i<frase.length();i++)
    {
        frase[i] = tolower(frase[i]);
    }
    return frase;
}
