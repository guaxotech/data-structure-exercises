#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct Funcionario
{
    int codigo;
    string nome;
    int idade;
    double salario;
};

struct No
{
    Funcionario dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
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

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "Número Total de Elementos:[" << lista->tamanho << "]\n{\n";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << "-> Nome: " << n->dado.nome  <<
        "\nCódigo: " << n->dado.codigo <<
        "\nIdade: " << n->dado.idade <<
        "\nSalário: " << n->dado.salario << endl;

        n = n->prox;

        if(n != NULL)
            cout << "----------------------\n";

    }
    cout << "}\n";
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}


bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}



bool removeL(Lista *lista, int valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.codigo != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}


/// -> Funcoes do Exercicio 1:

Funcionario leInicioL(Lista *lista)
{
    Funcionario func = {0, "Não há nenhum Funcionário Na Lista", 0, 0};

    if(!vaziaL(lista))
        return lista->inicio->dado;
    else
        return func;

}

bool removeInicioL(Lista *lista)
{
    if(!vaziaL(lista))
    {

    No* primeiro = lista->inicio;
    No* segundo = lista->inicio->prox;

    if(lista->tamanho >= 1)
    {
        lista->inicio = segundo;

        if(vaziaL(lista))
            lista->fim = lista->inicio;

        lista->tamanho--;
        return true;
    }
    else
    {
        return removeL(lista, lista->inicio->dado.codigo);
    }

    }
    else
    {
        return false;
    }

}

Funcionario leFinalL(Lista *lista)
{
    Funcionario func = {0, "Não há nenhum Funcionário Na Lista", 0, 0};

    if(!vaziaL(lista))
        return lista->fim->dado;
    else
        return func;
}
void imprimirMediaSalarialL(Lista *lista)
{
    double somaTotal = 0;
    No *n = lista->inicio;

    while(n != nullptr)
    {
        somaTotal += n->dado.salario;
        n = n->prox;
    }
    double mediaSalarial = (somaTotal/ (lista->tamanho) );
    cout<<"Média Salarial dos Funcionários dessa empresa: " << mediaSalarial <<endl;
}

void imprimirSalariosMenoresQueAMedia(Lista *lista)
{
    if(vaziaL(lista))
        return;

    double somaTotal = 0;
    No *n = lista->inicio;

    while(n != nullptr)
    {
        somaTotal += n->dado.salario;
        n = n->prox;
    }
    double mediaSalarial = (somaTotal/ (lista->tamanho) );

    n = lista->inicio;

    bool achou = false;

    cout<<"Lista dos funcionários que possuem um salário abaixo da média da empresa: " <<endl;

    while(n != nullptr)
    {
        if(n->dado.salario < mediaSalarial)
        {
            cout<<"--> " << n->dado.nome << endl;
            achou = true;
        }
        n = n->prox;
    }

    if(!achou)
        cout<< "-> Nenhum. " <<endl;

}

void ordenarListaOrdemAlfabetica(Lista *lista)
{
    No *i = lista->inicio;
    No *j = lista->inicio->prox;

    while(i != nullptr)
    {
        j = lista->inicio;

        while(j != nullptr)
        {
          if(i->dado.nome < j->dado.nome && i != j)
          {
            Funcionario fAux = i->dado;
            i->dado = j->dado;
            j->dado = fAux;
          }

          j = j->prox;
        }
        i = i->prox;
    }

    mostraL(lista);


}

/// -> Funcoes do Exercicio 2:


void inverterLista(Lista *lista)
{
    Lista lAux = Lista();

    No *n = lista->inicio;

    while(n != nullptr)
    {
        insereInicioL(&lAux, n->dado);
        n = n->prox;
    }

    mostraL(&lAux);

    n = lAux.inicio;

    while(removeInicioL(lista))
    {

    }

    while(n != nullptr)
    {
        insereFimL(lista, n->dado);
        n = n->prox;
    }
}

void mostraIdadeOrdenada(Lista *lista)
{

    if(lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    Lista lAux = Lista();

    No *n = lista->inicio;

    while(n != nullptr)
    {
        insereFimL(&lAux, n->dado);
        n = n->prox;
    }

    No *i = lAux.inicio;

    while(i != nullptr)
    {

        No *j = i->prox;

        while(j != nullptr)
        {
            if(i->dado.idade > j->dado.idade && i != j)
            {
                Funcionario dado = i->dado;
                i->dado = j->dado;
                j->dado = dado;
            }
            j = j->prox;
        }

        i = i->prox;

    }

    mostraL(&lAux);


}


void unirDuasListas(Lista *lista, Lista *lista2)
{
    No *n = lista2->inicio;

    while(n != nullptr)
    {
        insereFimL(lista, n->dado);
        n = n->prox;
    }

    mostraL(lista);
}

void interseccionarListas(Lista *lista, Lista *lista2, Lista *lInterseccao)
{
    No *n = lista->inicio;

    while(n != nullptr)
    {
        No* no = lista2->inicio;
        while(no != nullptr)
        {
            if (n->dado.codigo == no->dado.codigo)
            {
                insereFimL(lInterseccao, n->dado);
            }
            no = no->prox;
        }
        n = n->prox;
    }
}








#endif // _HPP_LISTA_DESCRITOR



