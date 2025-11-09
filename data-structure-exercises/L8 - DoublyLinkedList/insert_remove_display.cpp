#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista_dupla.hpp"

// Exercise: Demonstrates basic operations on a doubly linked list, 
// including inserting elements at the end, displaying the list, 
// and removing elements from both the beginning and the end.


main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");


    Lista lista = Lista();

    insereFimL(&lista, 10);
     insereFimL(&lista, 20);
      insereFimL(&lista, 30);
       insereFimL(&lista, 40);
        insereFimL(&lista, 50);
         insereFimL(&lista, 60);

    mostraL(&lista);

    //mostrarInversoL(&lista);


    /// Fun��o 2:

    cout<<"Removido do fim: -> " << removeFimL(&lista) << endl;

    cout<<"Removido do in�cio: -> " << removeInicioL(&lista) << endl;


}
