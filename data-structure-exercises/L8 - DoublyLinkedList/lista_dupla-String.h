#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    string dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->prox;
        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no in�cio da lista
bool insereInicioL(Lista *lista, int valor)
{
    No *novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo n� ser� adicionado no in�cio da lista, o ponteiro *ant do primeiro n� sempre � nulo
    novo->prox = lista->inicio;

    if (lista->fim == NULL)// //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}


No* buscaL(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ /// elemento está no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

bool removeL(Lista *lista, string valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}



/// ->>> Funções do exercício 1

bool insereFimL(Lista *lista, string valor)
{
    No *novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->ant = lista->fim; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = nullptr;

    if (lista->inicio == NULL)// //lista vazia?
    {
        //lista->fim = novo;
        lista->inicio = novo;
    }
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

string removeInicioL(Lista *lista)
{
   string dado = "";

   if(vaziaL(lista))
    return dado;

   dado = lista->inicio->dado;
   No *aux = lista->inicio;

   if(lista->inicio->prox != NULL)
    lista->inicio->prox->ant = NULL;
   else
    lista->fim = NULL;

   lista->inicio = lista->inicio->prox;
   lista->tamanho--;
   delete aux;

   return dado;

}

string removeFimL(Lista *lista)
{
    string dado = "";

    if(vaziaL(lista))
        return dado;

    if(lista->fim->ant != nullptr)
        lista->fim->ant->prox = NULL;
    dado = lista->fim->dado;
    No *aux = lista->fim;
    lista->fim = lista->fim->ant;
    lista->tamanho--;

    return dado;

}

/// ->>>> Funções do exercício 2


void removeTodos(Lista *lista, string valor)
{

    if(lista->inicio == nullptr)
    {
        return;
    }

    No *atual = lista->inicio;

    while(atual != nullptr)
    {
        if(atual->dado == valor)
        {
            if(atual->ant != nullptr) /// Ou seja, o valor não encontra-se no início
            {
                atual->ant->prox = atual->prox;
            }
            else                     /// Valor encontra-se no inicio
            {
                lista->inicio = atual->prox;
            }

            if(atual->prox != nullptr)
            {
            atual->prox->ant = atual->ant;
            }

            delete atual;
            //cout<<"REMOVEU"<<endl;
        }
        atual = atual->prox;
    }
}
// -->>>> Função que usei nesse exercicio (leMaiores)
/*
void insereOrdenado(Lista *lista, string valor)
{

    if(vaziaL(lista))
    {
      insereInicioL(lista, valor);
      return;
    }

    No *novo = new No();
    novo->dado = valor;

    No *atual = lista->inicio;

    while(atual != nullptr && novo->dado > atual->dado)
    {
        atual = atual->prox;
    }

    if(atual == lista->inicio)
    {
        // Inserir no Início
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
    else if(atual == nullptr)
    {
        // Inserir no Fim
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    else
    {
        // Inserir no meio
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
    }


    lista->tamanho++;




}

*/

/*
Lista leMaiores(Lista *lista, int k)
{

    // Criando uma listaAux e adicionando copiando os elementos para ela
    Lista lAux = Lista();

    No *n = lista->inicio;

    while(n != nullptr)
    {
        insereOrdenado(&lAux, n->dado);
        n = n->prox;
    }

    if(k >= lista->tamanho)
    {
        return lAux;
    }


    //mostraL(&lAux);

    Lista lSaida = Lista();


    for(int i=0; i<k; i++)
    {
        int maior = INT_MIN;

        No *n = lAux.inicio;
        No *noMaior = nullptr;

        while(n != nullptr)
        {
            if(n->dado > maior)
            {
                maior = n->dado;
                noMaior = n;
            }
            n = n->prox;
        }

        if(noMaior->ant != nullptr)
        {
            noMaior->ant->prox = noMaior->prox;
        }
        else
            lAux.inicio = noMaior->prox;

        if(noMaior->prox != nullptr)
            noMaior->prox->ant = noMaior->ant;

        insereOrdenado(&lSaida, maior);

        if(noMaior != nullptr)
        delete noMaior;
    }

    //delete lAux;
    return lSaida;






}
*/


#endif // _HPP_LISTA_DUPLA






