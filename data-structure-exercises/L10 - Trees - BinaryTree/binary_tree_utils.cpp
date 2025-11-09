#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include <climits>

using namespace std;

#include "binary_tree.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "English");

    int menu = -1;
    arv *top = nullptr;

    do {
        cout << "0 - Exit\n"
             << "1 - Insert\n"
             << "2 - Remove\n"
             << "3 - Traverse and Display\n"
             << "4 - Calculate height of left and right subtrees\n"
             << "5 - Calculate tree height\n"
             << "6 - Clear all tree nodes\n"
             << "7 - Find the level of a number\n"
             << "8 - Display with indentation\n"
             << "9 - Total number of Nodes / Leaves\n"
             << "10 - Find Sibling\n"
             << "11 - Show Cousins\n"
             << "12 - Show Uncle\n"
             << "13 - Show Grandparent\n"
             << "14 - Show Parent\n"
             << "15 - Check if Balanced\n"
             << "16 - Find Largest and Smallest Elements\n"
             << "17 - Find Predecessor and Successor\n"
             << "18 - Count Nodes at a Given Level\n"
             << "19 - Check if Strictly Binary\n"
             << "20 - Check if Full" << endl;

        cin >> menu;

        if (menu == 1) {
            int num;
            cout << "Number: ";
            cin >> num;
            inserir(&top, num);

            cout << num << " was inserted into the tree!" << endl;
        }
        else if (menu == 2) {
            int num;
            cout << "Number: ";
            cin >> num;
            if (consulta(top, num)) {
                remover(&top, num);
            } else {
                cout << "Value not found." << endl;
            }
        }
        else if (menu == 3) {
            if (!testa_vazia(top)) {
                cout << "Pre-Order: " << endl;
                mostra_1(top);
                cout << "\nIn-Order: " << endl;
                mostra_2(top);
                cout << "\nPost-Order: " << endl;
                mostra_3(top);
            } else {
                cout << "TREE IS EMPTY!" << endl;
            }

            cout << "\nPress any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 4) {
            if (!testa_vazia(top)) {
                int num;
                cout << "Enter the parent node value: ";
                cin >> num;
                calcular_altura_subarvores(&top, num);
            } else {
                cout << "TREE IS EMPTY!" << endl;
            }
        }
        else if (menu == 5) {
            if (!testa_vazia(top)) {
                cout << "Tree Height: " << calcular_altura(top);
            } else {
                cout << "TREE IS EMPTY!" << endl;
            }
        }
        else if (menu == 6) {
            if (!testa_vazia(top)) {
                top = limpar_nos(&top);
                cout << "Removing all nodes..." << endl;
            } else {
                cout << "TREE IS EMPTY!" << endl;
            }
        }
        else if (menu == 7) {
            if (!testa_vazia(top)) {
                int num;
                cout << "Number: ";
                cin >> num;

                int found = encontrar_nivel(top, num, 0);

                if (found != -1) {
                    cout << "Number " << num << " is at level " << found << endl;
                } else {
                    cout << "This number is not in the tree." << endl;
                }
            } else {
                cout << "TREE IS EMPTY!" << endl;
            }
        }
        else if (menu == 8) {
            exibir_paragrafacao(top, 0);

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 9) {
            cout << "Total Nodes: " << quantidade_total_nos(top) << endl;
            cout << "Total Leaves: " << quantidade_total_folhas(top) << endl;
            cout << "Balanced? ";
            if (verificar_balanceada(top))
                cout << "Yes";
            else
                cout << "No";
            cout << "\nPress any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 10) {
            int num;
            cout << "Number: ";
            cin >> num;

            if (consulta(top, num)) {
                int sibling = retornar_irmao(top, num);
                if (sibling != -1)
                    cout << "Sibling: " << sibling << endl;
                else
                    cout << "This node is an only child." << endl;
            } else {
                cout << "Number not found in the tree." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 11) {
            int num;
            cout << "Number: ";
            cin >> num;

            if (consulta(top, num)) {
                cout << "Cousin(s): ";
                mostrar_primos(top, num);
                cout << endl;
            } else {
                cout << "Number not found in the tree." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 12) {
            int num;
            cout << "Find Uncle\nNumber: ";
            cin >> num;

            mostrar_tio(top, num);
        }
        else if (menu == 13) {
            int num;
            cout << "Find Grandparent\nNumber: ";
            cin >> num;

            mostrar_avo(top, num);
        }
        else if (menu == 14) {
            int num;
            cout << "Find Parent\nNumber: ";
            cin >> num;

            if (top->info == num)
                cout << "This element is the Root of the Tree." << endl;
            else
                mostrar_pai(top, num);
        }
        else if (menu == 15) {
            cout << "Is it balanced? ";
            if (verificar_balanceada(top))
                cout << "Yes." << endl;
            else
                cout << "No." << endl;

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            getchar();
        }
        else if (menu == 16) {
            if (!testa_vazia(top)) {
                maior_menor_elementos(top);
            }
        }
        else if (menu == 17) {
            if (!testa_vazia(top)) {
                int num;
                cout << "Number: ";
                cin >> num;

                buscar_sucessor_predecessor(top, num);
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                getchar();
            }
        }
        else if (menu == 18) {
            if (!testa_vazia(top)) {
                int level;
                cout << "Level: ";
                cin >> level;

                cout << "Nodes at this level: " << quantidade_nos_nivel(top, 0, level) << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                getchar();
            }
        }
        else if (menu == 19) {
            if (!testa_vazia(top)) {
                if (eh_estritamente_binaria(top))
                    cout << "Yes, it is strictly binary." << endl;
                else
                    cout << "No, it is not strictly binary." << endl;
            }
        }
        else if (menu == 20) {
            if (eh_cheia(top))
                cout << "Yes, it is full." << endl;
            else
                cout << "No, it is not full." << endl;

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            getchar();
        }

        Sleep(400);
        system("cls");
    } while (menu != 0);
}
