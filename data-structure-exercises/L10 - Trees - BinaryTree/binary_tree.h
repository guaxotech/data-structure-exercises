#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

/*
    Binary Tree Implementation in C++
    ---------------------------------
    This module contains a complete set of functions for creating,
    manipulating, and analyzing binary trees, including insertion,
    deletion, traversal, queries, height calculation, balance checking,
    and structural properties.

    Author: Guaxo
    Language: C++
    Last update: 2025
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* ----------------------------------------------------------
   Base structure of the binary tree
-----------------------------------------------------------*/
struct arv {
    int info;      // Value stored in the node
    arv *sae;      // Pointer to the left subtree
    arv *sad;      // Pointer to the right subtree
};

/* ----------------------------------------------------------
   Checks if the tree is empty.
   Returns 1 (true) if empty, otherwise 0.
-----------------------------------------------------------*/
int testa_vazia(arv *t) {
    if (t == NULL)
        return 1;
    if (t->info == NULL)
        return 1;
    return 0;
}

/* ----------------------------------------------------------
   Inserts a new node into the tree in an ordered manner
   (smaller values go to the left, larger values to the right)
-----------------------------------------------------------*/
void inserir(arv **t, int num) {
    if (*t == NULL) {
        *t = new arv;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->info = num;
    } else {
        if (num < (*t)->info)
            inserir(&(*t)->sae, num);
        else
            inserir(&(*t)->sad, num);
    }
}

/* ----------------------------------------------------------
   Pre-order traversal (root → left → right)
-----------------------------------------------------------*/
void mostra_1(arv *t) {
    cout << "<";
    if (!testa_vazia(t)) {
        cout << t->info;
        mostra_1(t->sae);
        mostra_1(t->sad);
    }
    cout << ">";
}

/* ----------------------------------------------------------
   In-order traversal (left → root → right)
   Produces output in ascending order.
-----------------------------------------------------------*/
void mostra_2(arv *t) {
    cout << "<";
    if (!testa_vazia(t)) {
        mostra_2(t->sae);
        cout << t->info;
        mostra_2(t->sad);
    }
    cout << ">";
}

/* ----------------------------------------------------------
   Post-order traversal (left → right → root)
-----------------------------------------------------------*/
void mostra_3(arv *t) {
    cout << "<";
    if (!testa_vazia(t)) {
        mostra_3(t->sae);
        mostra_3(t->sad);
        cout << t->info;
    }
    cout << ">";
}

/* ----------------------------------------------------------
   Query: checks whether a value exists in the tree
-----------------------------------------------------------*/
bool consulta(arv *t, int v) {
    if (testa_vazia(t))
        return 0;
    return t->info == v || consulta(t->sae, v) || consulta(t->sad, v);
}

/* ----------------------------------------------------------
   Removes a node from the tree while preserving its structure
-----------------------------------------------------------*/
bool remover(arv **t, int num) {
    if (num < (*t)->info)
        remover(&(*t)->sae, num);
    else if (num > (*t)->info)
        remover(&(*t)->sad, num);
    else {
        arv *aux = *t;
        // Case 1: leaf node
        if (((*t)->sae == nullptr) && ((*t)->sad == nullptr)) {
            delete (aux);
            (*t) = nullptr;
        }
        // Case 2: only right subtree
        else if ((*t)->sae == nullptr) {
            (*t) = (*t)->sad;
            aux->sad = nullptr;
            delete (aux);
        }
        // Case 3: only left subtree
        else if ((*t)->sad == nullptr) {
            (*t) = (*t)->sae;
            aux->sae = nullptr;
            delete (aux);
        }
        // Case 4: two subtrees
        else {
            aux = (*t)->sae;
            while (aux->sad != nullptr) {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            remover(&(*t)->sae, aux->info);
        }
    }
}

/* ----------------------------------------------------------
   Calculates the tree height (longest path from root to leaf)
-----------------------------------------------------------*/
int calcular_altura(arv *t) {
    if (t == nullptr) return -1;
    int altura_esq = calcular_altura(t->sae);
    int altura_dir = calcular_altura(t->sad);
    return 1 + max(altura_esq, altura_dir);
}

/* ----------------------------------------------------------
   Finds a node with a given value and returns its pointer
-----------------------------------------------------------*/
arv* acharNumero(arv *t, int num) {
    if (t == NULL) return NULL;
    if (t->info == num) return t;
    arv *esq = acharNumero(t->sae, num);
    if (esq != NULL) return esq;
    return acharNumero(t->sad, num);
}

/* ----------------------------------------------------------
   Calculates and displays the height of left and right subtrees
   of a specific node
-----------------------------------------------------------*/
int calcular_altura_subarvores(arv **t, int num) {
    arv *no = acharNumero(*t, num);
    if (no == NULL) {
        cout << "The number " << num << " does not exist in the tree!" << endl;
        return -1;
    }
    int altura_esquerda = calcular_altura(no->sae);
    int altura_direita = calcular_altura(no->sad);
    cout << "Left Subtree Height: " << altura_esquerda << endl;
    cout << "Right Subtree Height: " << altura_direita << endl;
}

/* ----------------------------------------------------------
   Removes all nodes from the tree, freeing memory
-----------------------------------------------------------*/
arv* limpar_nos(arv **t) {
    if ((*t) == nullptr) return nullptr;
    limpar_nos(&(*t)->sae);
    limpar_nos(&(*t)->sad);
    (*t)->sae = nullptr;
    (*t)->sad = nullptr;
    delete *t;
    return nullptr;
}

/* ----------------------------------------------------------
   Returns the level (depth) of a given value in the tree
-----------------------------------------------------------*/
int encontrar_nivel(arv *t, int num, int nivel) {
    if (t == nullptr) return -1;
    if (t->info == num)
        return nivel;
    int achou = encontrar_nivel(t->sae, num, nivel + 1);
    if (achou != -1)
        return achou;
    return encontrar_nivel(t->sad, num, nivel + 1);
}

/* ----------------------------------------------------------
   Displays the tree in a hierarchical indentation format
-----------------------------------------------------------*/
void exibir_paragrafacao(arv *t, int nivel) {
    if (t == nullptr)
        return;
    for (int i = 0; i < nivel; i++)
        cout << ".";
    cout << t->info << endl;
    exibir_paragrafacao(t->sae, nivel + 1);
    exibir_paragrafacao(t->sad, nivel + 1);
}

/* ----------------------------------------------------------
   Returns the total number of nodes in the tree
-----------------------------------------------------------*/
int quantidade_total_nos(arv *t) {
    if (t == nullptr)
        return 0;
    return 1 + quantidade_total_nos(t->sae) + quantidade_total_nos(t->sad);
}

/* ----------------------------------------------------------
   Counts how many nodes are leaves (no children)
-----------------------------------------------------------*/
int quantidade_total_folhas(arv *t) {
    if (t == nullptr)
        return 0;
    if (t->sae == nullptr && t->sad == nullptr)
        return 1;
    return quantidade_total_folhas(t->sae) + quantidade_total_folhas(t->sad);
}

/* ----------------------------------------------------------
   Returns the value of a node's sibling
-----------------------------------------------------------*/
int retornar_irmao(arv *t, int num) {
    if (t == nullptr)
        return -1;
    if (t->sae && t->sae->info == num) {
        if (t->sad) return (t->sad->info);
        else return -1;
    }
    if (t->sad && t->sad->info == num) {
        if (t->sae) return (t->sae->info);
        else return -1;
    }
    int irmao = retornar_irmao(t->sae, num);
    if (irmao != -1) return irmao;
    return retornar_irmao(t->sad, num);
}

/* ----------------------------------------------------------
   Displays the cousins of a specific node
-----------------------------------------------------------*/
void mostrar_primos(arv *t, int num) {
    if (t == nullptr)
        return;

    if (t->sae && t->sad) {
        if (t->sae->sae && t->sae->sad) {
            if (t->sae->sae->info == num || t->sae->sad->info == num) {
                if (t->sad->sae) cout << t->sad->sae->info << " ";
                if (t->sad->sad) cout << t->sad->sad->info << " ";
            }
        }
        if (t->sad->sae && t->sad->sad) {
            if (t->sad->sae->info == num || t->sad->sad->info == num) {
                if (t->sae->sae) cout << t->sae->sae->info << " ";
                if (t->sae->sad) cout << t->sae->sad->info << " ";
            }
        }
    }

    mostrar_primos(t->sae, num);
    mostrar_primos(t->sad, num);
}

/* ----------------------------------------------------------
   Displays the uncle of a given node
-----------------------------------------------------------*/
void mostrar_tio(arv *t, int num) {
    if (!t)
        return;
    if (t->sae) {
        if ((t->sae->sae && t->sae->sae->info == num) || (t->sae->sad && t->sae->sad->info == num)) {
            if (t->sad) cout << "Uncle of " << num << ": " << t->sad->info;
        }
    }
    if (t->sad) {
        if ((t->sad->sae && t->sad->sae->info == num) || (t->sad->sad && t->sad->sad->info == num)) {
            if (t->sae) cout << "Uncle of " << num << ": " << t->sae->info;
        }
    }
    mostrar_tio(t->sae, num);
    mostrar_tio(t->sad, num);
}

/* ----------------------------------------------------------
   Displays the grandfather of a given node
-----------------------------------------------------------*/
void mostrar_avo(arv *t, int num) {
    if (!t)
        return;
    if (t->sae) {
        if ((t->sae->sae && t->sae->sae->info == num) || (t->sae->sad && t->sae->sad->info == num)) {
            cout << "Grandfather of " << num << ": " << t->info;
            return;
        }
    }
    if (t->sad) {
        if ((t->sad->sae && t->sad->sae->info == num) || (t->sad->sad && t->sad->sad->info == num)) {
            cout << "Grandfather of " << num << ": " << t->info;
            return;
        }
    }
    mostrar_avo(t->sae, num);
    mostrar_avo(t->sad, num);
}

/* ----------------------------------------------------------
   Displays the parent of a given node
-----------------------------------------------------------*/
void mostrar_pai(arv *t, int num) {
    if (!t)
        return;
    if ((t->sae && t->sae->info == num) || (t->sad && t->sad->info == num)) {
        cout << "Parent of " << num << ": " << t->info;
    }
    mostrar_pai(t->sae, num);
    mostrar_pai(t->sad, num);
}

/* ----------------------------------------------------------
   Checks if the tree is balanced (AVL-like)
-----------------------------------------------------------*/
bool verificar_balanceada(arv *t) {
    if (!t)
        return true;
    int altura_esq = calcular_altura(t->sae);
    int altura_dir = calcular_altura(t->sad);
    if (abs(altura_esq - altura_dir) > 1)
        return false;
    return verificar_balanceada(t->sae) && verificar_balanceada(t->sad);
}

/* ----------------------------------------------------------
   Finds and displays the largest and smallest elements in the tree
-----------------------------------------------------------*/
void percorrer_maior_menor_elementos(arv *t, int &menor, int &maior) {
    if (!t)
        return;
    if (t->info < menor)
        menor = t->info;
    if (t->info > maior)
        maior = t->info;
    percorrer_maior_menor_elementos(t->sae, menor, maior);
    percorrer_maior_menor_elementos(t->sad, menor, maior);
}

void maior_menor_elementos(arv *t) {
    if (!t)
        return;
    int menor = INT_MAX, maior = INT_MIN;
    percorrer_maior_menor_elementos(t, menor, maior);
    cout << "Smallest Element: " << menor << " | Largest Element: " << maior << endl;
}

/* ----------------------------------------------------------
   Finds the successor and predecessor of a given value
-----------------------------------------------------------*/
void percorrer_sucessor_predecessor(arv *t, int num, int &sucessor, int &predecessor) {
    if (!t)
        return;
    int distancia = abs(t->info - num);
    if (t->info < num && distancia < abs(predecessor - num))
        predecessor = t->info;
    if (t->info > num && distancia < abs(sucessor - num))
        sucessor = t->info;
    percorrer_sucessor_predecessor(t->sae, num, sucessor, predecessor);
    percorrer_sucessor_predecessor(t->sad, num, sucessor, predecessor);
}

void buscar_sucessor_predecessor(arv *t, int num) {
    int sucessor = (INT_MAX - num);
    int predecessor = (INT_MIN + num);
    percorrer_sucessor_predecessor(t, num, sucessor, predecessor);
    cout << "Predecessor: " << predecessor << " - Successor: " << sucessor << endl;
}

/* ----------------------------------------------------------
   Returns the number of nodes in a specific level
-----------------------------------------------------------*/
int quantidade_nos_nivel(arv *t, int nivel_atual, int nivel_desejado) {
    if (!t)
        return 0;
    if (nivel_atual == nivel_desejado)
        return 1;
    return quantidade_nos_nivel(t->sae, nivel_atual + 1, nivel_desejado)
         + quantidade_nos_nivel(t->sad, nivel_atual + 1, nivel_desejado);
}

/* ----------------------------------------------------------
   Checks if the tree is strictly binary
   (each node has 0 or 2 children)
-----------------------------------------------------------*/
bool eh_estritamente_binaria(arv *t) {
    if (!t)
        return true;
    if ((t->sae && t->sad) || (!t->sae && !t->sad))
        return eh_estritamente_binaria(t->sae) && eh_estritamente_binaria(t->sad);
    else
        return false;
}

/* ----------------------------------------------------------
   Checks if the tree is full
   (all levels except the last are completely filled)
-----------------------------------------------------------*/
bool eh_cheia(arv *t) {
    if (!t)
        return true;
    int altura_total = calcular_altura(t);
    int quant_nos = quantidade_total_nos(t);
    int esperado = (pow(2, altura_total) - 1);
    cout << "Height: " << altura_total << endl;
    cout << "Total nodes: " << quant_nos << endl;
    cout << "Expected: " << esperado << endl;
    return esperado == quant_nos;
}

#endif // ARVORE_BINARIA_H_INCLUDED
