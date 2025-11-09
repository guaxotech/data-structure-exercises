#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "lista_descritor-Funcionario.hpp"

// Exercise: Creates two doubly linked lists with a descriptor, performs intersection of the lists, 
// and demonstrates basic list operations like insertion and display.


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");



   Lista lista = Lista();
   insereInicioL(&lista, {1, "L�o", 20, 20000.00});
   insereInicioL(&lista, {4, "Lucas", 40, 32000.00});
   insereInicioL(&lista, {5, "Amaral", 58, 200000.00});
   insereInicioL(&lista, {6, "Patrick", 40, 100000.00});
   insereInicioL(&lista, {3, "Messi", 38, 14700.00});

   //mostraL(&lista);

   //cout<<"\nAp�s a invers�o: " <<endl;

   //inverterLista(&lista);

   //cout<<"\nOrdena��o por Idade: " <<endl;

   //mostraIdadeOrdenada(&lista);




   // Criando uma segunda lista:

   Lista lista2 = Lista();
   insereInicioL(&lista2, {7, "Heisenberg", 30, 2000.00});
   insereInicioL(&lista2, {8, "Suarez", 38, 32000.00});
   insereInicioL(&lista2, {9, "NJ", 32, 2000.00});
   insereInicioL(&lista2, {6, "Patrick", 40, 100000.00});
   insereInicioL(&lista2, {3, "Messi", 38, 14700.00});

   //unirDuasListas(&lista, &lista2);

   Lista listaInterseccao = Lista();

   interseccionarListas(&lista, &lista2, &listaInterseccao);
















}
