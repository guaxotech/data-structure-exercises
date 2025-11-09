#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

/**/

#include "pilha-dinamica.hpp"

void substituir(Pilha *p1, Pilha *p2, int i, int f)
{
    if (buscaP(p1, i) && buscaP(p1, f))
    {
        Pilha pAux;   // Elementos situados depois de f
        Pilha pAux2;  // Elementos situados entre i e f (descartados)
        Pilha pAux3;  // Elementos antes de i
        Pilha copiaP2; // Cópia de p2 para não destruí-la

        // Copiar p2 para copiaP2 (mantendo p2 intacta)
        Pilha temp;

        while (!vaziaP(p2))
            empilhaP(&temp, desempilhaP(p2));
        while (!vaziaP(&temp))
        {
            int v = desempilhaP(&temp);
            empilhaP(p2, v);       // devolve em p2
            empilhaP(&copiaP2, v); // copia em copiaP2
        }

        // Retira elementos até encontrar i
        while (!vaziaP(p1))
        {
            int valor = desempilhaP(p1);
            if (valor != i)
                empilhaP(&pAux, valor);
            else
                break;
        }

        // Retira elementos até encontrar f
        while (!vaziaP(p1))
        {
            int valor = desempilhaP(p1);
            if (valor != f)
                empilhaP(&pAux2, valor); // descartados
            else
                break;
        }

        // Retira o restante (antes de i)
        while (!vaziaP(p1))
            empilhaP(&pAux3, desempilhaP(p1));

        // Reconstrução na ordem correta: pAux3, i, copiaP2, f, pAux
        while (!vaziaP(&pAux3))
            empilhaP(p1, desempilhaP(&pAux3));

        empilhaP(p1, i);

        while (!vaziaP(&copiaP2))
            empilhaP(p1, desempilhaP(&copiaP2));

        empilhaP(p1, f);

        while (!vaziaP(&pAux))
            empilhaP(p1, desempilhaP(&pAux));
    }
}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Pilha p1;

   empilhaP(&p1, 10);
   empilhaP(&p1, 20);
   empilhaP(&p1, 30);
   empilhaP(&p1, 40);
   empilhaP(&p1, 50);

   Pilha p2;

   empilhaP(&p2, 60);
   empilhaP(&p2, 70);
   empilhaP(&p2, 80);
   empilhaP(&p2, 90);
   empilhaP(&p2, 100);

   substituir(&p1, &p2, 1, 3);

   mostraP(&p1);
   mostraP(&p2);

}
