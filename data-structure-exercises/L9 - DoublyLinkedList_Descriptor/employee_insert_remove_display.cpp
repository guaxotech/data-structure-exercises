#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

// Exercise: Demonstrates insertion at the beginning and end of a doubly linked list with a descriptor, 
// displays the list, calculates average salary, lists employees with salaries below the average, 
// and sorts the list alphabetically.


#include "lista_descritor-Funcionario.hpp"

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    Lista lista = Lista();
    insereInicioL(&lista, {1, "Vito", 20, 20000.00});
    insereInicioL(&lista, {4, "Lucas", 40, 32000.00});


    /*
    cout<<"\nFun��o leInicioL : " <<endl;

    cout<< "Nome: " << leInicioL(&lista).nome << "\n"
    "Idade: " << leInicioL(&lista).idade << "\n" <<
    "Sal�rio: " << leInicioL(&lista).salario<<endl;

    */

    /*
    cout<<"\nFun��o removeInicioL: " <<endl;

    if(!vaziaL(&lista))
    cout<<"O Funcion�rio " << leInicioL(&lista).nome << " foi removido da lista! " << endl;
    removeInicioL(&lista);

    */




    cout<<"\nFun��o insereInicioL: " <<endl;

    if(insereInicioL(&lista, {2, "Jalin", 24, 15000.00}))
        cout<<"Funcion�rio inserido com sucesso! " <<endl;





    cout<<"\nFun��o insereFimL: " <<endl;

    if(insereFimL(&lista, {3, "Lionel", 32, 147000.00}))
        cout<<"Funcion�rio inserido com sucesso! " <<endl;




    //cout<<"\nFun��o LeFinalL: " <<endl;

    /*cout<< "Nome: " << leFinalL(&lista).nome << "\n"
    "Idade: " << leInicioL(&lista).idade << "\n" <<
    "Sal�rio: " << leInicioL(&lista).salario<<endl;
    */

    insereInicioL(&lista, {5, "Amaral", 58, 200000.00});

    insereInicioL(&lista, {6, "Zeus", 3000, 1000000.00});




    mostraL(&lista);

    imprimirMediaSalarialL(&lista);

    imprimirSalariosMenoresQueAMedia(&lista);

    ordenarListaOrdemAlfabetica(&lista);





















}
