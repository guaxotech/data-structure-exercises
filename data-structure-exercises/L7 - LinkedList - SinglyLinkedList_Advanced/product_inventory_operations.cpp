#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

#include "lista-Produtos.hpp"
int soma(No **lista, string nome)
{
    string nomeCopia = nome;
    int cont = 0;
    /*for(int i=0; i<nomeCopia.size(); i++)
    {
        nomeCopia[i] = tolower(nomeCopia[i]);
    }
    */

    No *n = *lista;

    while(n != NULL)
    {
        if(n->dado.nome == nome)
        {
            cont += n->dado.quantidade;
        }
        n = n->prox;
    }
    return cont;
}
int contProdutos(No **lista, string nome)
{
    No* n = *lista;
    int cont =0;
    while(n != NULL)
    {
        if(n->dado.nome == nome)
            cont++;
        n = n->prox;
    }

    return cont;
}
int somaIntervalo(No **lista, int i, int f)
{
    No *teste = *lista;
    int tam = 0;
    while(teste != NULL)
    {
        tam++;
        teste = teste->prox;
    }
    if( i+f > tam || i > f )
    {
        return 0;
    }

    No *n = *lista;
    int contPosicao = 0;
    int quantidadeTotal = 0;
    while(n != NULL)
    {
        if(contPosicao >= i && contPosicao <= f)
        {
            quantidadeTotal += n->dado.quantidade;
        }
        n = n->prox;
    }

    return quantidadeTotal;
}
void combinarProd(No **lista, string nome)
{
    No *teste = *lista;
    No *listaSaida = NULL;

    int tam = 0;
    while(teste != NULL)
    {
        tam++;
        teste = teste->prox;
    }

    No *n = *lista;
    No *no = NULL;
    no = n->prox;
    bool entrouDenovo = false;

    //cout << (n->prox)->prox << endl;

    while(n->prox != nullptr)
    {
        int cont = 0;

        while(no != nullptr)
        {
            cont = 0;
            //cout << n->dado.nome << " | " << no->dado.nome << endl;
            if(n->dado.nome == no->dado.nome && n->dado.nome == nome)
            {
                cont += no->dado.quantidade;
                n->dado.quantidade += cont;
                //cout<<"Entrou laço if" <<endl;
                if(removeL(&n->prox, nome))
                {
                    //cout << "removeu " << nome << endl;
                }
            }
         no = no->prox;
        }
        n = n->prox;
        no = n->prox;

    }


}
bool verificaIntervalo(No **lista, int i1, int f1, int i2, int f2)
{
    No *teste = *lista;
    int tam=0;
    while(teste != NULL)
    {
        tam++;
        teste = teste->prox;
    }
    cout<<"Numero de elementos na fila: " << tam << endl;

    /*if( i1 + f1 > tam || i2 + f2 > tam)
        return false;
     */
    int contIntervalo = 0;

    No *intervalo1 = NULL;
    No *intervalo2 = NULL;
    No *n = *lista;

    /// Separarando os intervalos:

    while(n != NULL)
    {
     if(contIntervalo >= i1 && contIntervalo <= f1)
     {
         insereFinalL(&intervalo1, n->dado);
     }
     else if(contIntervalo >= i2 && contIntervalo <= f2)
     {
         insereFinalL(&intervalo2, n->dado);
     }
     n = n->prox;
     contIntervalo++;
    }
    mostraL(&intervalo1);
    mostraL(&intervalo2);


    /// Comparando os intervalos:

    int quantIntervalo1 = 0;
    int quantIntervalo2 = 0;

    while(intervalo1 != NULL)
    {
        quantIntervalo1 += intervalo1->dado.quantidade;
        intervalo1 = intervalo1->prox;
    }

    while(intervalo2 != NULL)
    {
        quantIntervalo2 += intervalo2->dado.quantidade;
        intervalo2 = intervalo2->prox;
    }


    if(quantIntervalo1 != quantIntervalo2)
    {
        return false;
    }
    else
    {
        return true;
    }

}

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    No* lista = NULL;

    cout<< "Função soma(&lista, nome) " <<endl;

    Produto p1 = {"Furadeira", 10, 120.90};

    insereFinalL(&lista, p1);

    cout<<"-> Quantidade total de produtos: " << soma(&lista, "Furadeira") <<endl;

    cout<< "\nFunção contProdutos(lista, nome)" << endl;


    insereFinalL(&lista, p1);

    cout<<"-> Quantidade de produtos registrados que possuem esse nome: " << contProdutos(&lista, "Furadeira") << endl;

    cout<<"\nFunção somaIntervalo(lista, I, F)" <<endl;

    int inicio = 0, fim = 1;
    cout<<"-> Soma da quantidade dos produtos no intervalo de " << inicio << " até " << fim << ": ";
    cout<<somaIntervalo(&lista, inicio, fim)<<endl;

    insereFinalL(&lista, p1);

    cout<<"\nFunção combinarProd(lista, nome): " <<endl;

    Produto p2 = {"Makita", 20, 150};
    insereFinalL(&lista, p2);
    insereInicioL(&lista, p2);

    mostraL(&lista);
    combinarProd(&lista, "Furadeira");
    mostraL(&lista);



    ///
    insereFinalL(&lista, {"Betoneira", 10, 900});
    insereFinalL(&lista, {"Carrinho de Mão", 20, 500});
    ///

    cout<<"\nFunção verificaIntervalos: " << endl;

    int i1=0, f1=1, i2=2, f2=4;   // trocar f2 = 3 para verificar o false;

    if(verificaIntervalo(&lista,i1,f1,i2,f2)){
        cout<<"A soma da quantidade de produtos no intervalo [" << i1 << "],[" << i2 << "] e [" << f1 << "],[" << f2 << "] é igual" <<endl;
    }
    else
        cout<<"A soma da quantidade de produtos no intervalo [" << i1 << "],[" << i2 << "] e [" << f1 << "],[" << f2 << "] é diferente" <<endl;




}
