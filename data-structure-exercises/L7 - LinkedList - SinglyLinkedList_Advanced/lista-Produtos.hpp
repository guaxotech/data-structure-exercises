#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA
struct Produto
{
    string nome;
    int quantidade;
    float preco;
};

struct No
{
    Produto dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado.quantidade;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no início da lista
bool insereInicioL(No **lista, Produto valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
Produto leInicioL(No **lista)
{
    Produto dado;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
Produto removeInicioL(No **lista)
{
    No* aux;
    Produto dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}




///remover um nó da lista com um valor específico


bool removeL(No **lista, string valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado.nome != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}



/*
No* buscaL(No **lista, string valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if(strcmp(n->dado.nome, valor) == 0)
            return n;

        n = n->prox;
    }

    return NULL;
}
*/

/// Funções adicionadas:

void insereFinalL(No **lista, Produto valor)
{
    No *n = *lista;
    No *novo = new No();
    novo->dado = valor;

    if(n == NULL)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    while(n->prox != NULL)
    {
       n = n->prox;
    }

    n->prox = novo;
    novo->prox = NULL;

}


#endif // _HPP_LISTA_DINAMICA









