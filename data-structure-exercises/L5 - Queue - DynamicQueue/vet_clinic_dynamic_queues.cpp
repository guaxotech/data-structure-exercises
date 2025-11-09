#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>

using namespace std;

#include "fila-dinamica-Veterinaria.h"
#include "pilha-dinamica-veterinaria.h"

// Exercise: Veterinary Clinic Queue Management (Dynamic)
// Description: System managing two dynamic queues (priority and non-priority) and two stacks for served cases (wild/domestic). Includes: enqueue patient, attend respecting 3-to-1 rule, show queues, list served, remove from stack, and find youngest severe case.
// Data Type: Ficha (name, age, type S/D, condition E/G)


void exibirMenu();
string testar_Tipo (char tipo)
    {
        if(tipo == 'S')
            return "Selvagem";
        else
            return "Dom�stico";
    }
string testar_QC(char quadroClinico)
{
    if(quadroClinico == 'E')
        return "Est�vel";
    else
        return "Grave";
}
main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int menu = -1;
    Fila fP;
    Fila fN;
    Pilha pANIMALS;
    Pilha pANIMALD;

    int contAtendimentosPrioritarios = 0;

    while(menu != 0)
    {

    cout<<"----> ### MENU ### <----"<<endl;
    cout<<"1 - Criar ficha e adicionar na fila "<<endl;
    cout<<"2 - Atender pr�xima ficha da fila "<<endl;
    cout<<"3 - Mostrar os dados das fichas de atendimento(todas filas) "<<endl;
    cout<<"4 - Listar informa��es mais espec�ficas sobre as filas: "<<endl;
    cout<<"5 - Listar as fichas j� atendidas: "<<endl;
    cout<<"6 - Remover uma ficha da pilha: " <<endl;
    cout<<"7 - Mostrar o nome do animal armazenado nas pilhas que possui a Menor Idade com o quadro cl�nico grave: " <<endl;
    cout<<"0 - Sair "<<endl;
    cout<<"------------------------"<<endl;

    cin>>menu;

    cin.ignore();

    if(menu == 1)
    {
        Ficha f1 = {" ", 0, ' ', ' '};
        cout<<"Nome: "<<endl;
        getline(cin, f1.nome);
        cout<<"Idade: "<<endl;
        cin>>f1.idade;

        while(f1.tipo != 'S' && f1.tipo != 'D' && f1.tipo != 's' && f1.tipo != 'd')
        {
        cout<<"Tipo: (S-Selvagem, D-Dom�stico) : "<<endl;
        cin>>f1.tipo;
        }
        f1.tipo = toupper(f1.tipo);

        while(f1.quadroClinico != 'E' && f1.quadroClinico != 'G' && f1.quadroClinico != 'e' && f1.quadroClinico != 'g')
        {
        cout<<"Quadro Cl�nico: (E-Est�vel, G-Grave)"<<endl;
        cin>>f1.quadroClinico;
        }
        f1.quadroClinico = toupper(f1.quadroClinico);
        f1 = {f1.nome, f1.idade, f1.tipo, f1.quadroClinico};
        if(f1.quadroClinico == 'G')
        {
            enfileiraF(&fP, f1);
        }
        else
        {
            enfileiraF(&fN, f1);
        }
    }
        else if(menu == 2)
        {
            if(vaziaF(&fP) && !vaziaF(&fN))                        /// Se a priorit�ria estiver vazia, atender a n�o-priorit�ria
            {
                Ficha ficha = desenfileiraF(&fN);
                string nome = ficha.nome;
                int idade = ficha.idade;
                char tipo = ficha.tipo;
                char quadroClinico = ficha.quadroClinico;
                if(tipo == 'S')
                {
                    empilhaP(&pANIMALS, ficha);
                }
                else
                {
                    empilhaP(&pANIMALD, ficha);
                }
                cout<<"O Paciente " << nome << " foi atendido."<<endl;

            }
            else
            {
                if(vaziaF(&fN) && !vaziaF(&fP))                            /// Se a n�o priorit�ria estiver vazia, atender a priorit�ria(sem incrementar o cont);
                {
                    Ficha ficha = desenfileiraF(&fP);
                    string nome = ficha.nome;
                    int idade = ficha.idade;
                    char tipo = ficha.tipo;
                    char quadroClinico = ficha.quadroClinico;
                    if(tipo == 'S')
                    {
                        empilhaP(&pANIMALS, ficha);
                    }
                    else
                    {
                        empilhaP(&pANIMALD, ficha);
                    }
                    cout<<"O Paciente " << nome << " foi atendido."<<endl;

                }
                else if(!vaziaF(&fP) && !vaziaF(&fN))
                {
                    if(contAtendimentosPrioritarios <= 3)
                    {
                        Ficha ficha = desenfileiraF(&fP);
                        string nome = ficha.nome;
                        int idade = ficha.idade;
                        char tipo = ficha.tipo;
                        char quadroClinico = ficha.quadroClinico;
                        if(tipo == 'S')
                        {
                            empilhaP(&pANIMALS, ficha);
                        }
                        else
                        {
                            empilhaP(&pANIMALD, ficha);
                        }
                        contAtendimentosPrioritarios++;
                        cout<<"O Paciente " << nome << " foi atendido."<<endl;
                    }
                    else
                    {
                        Ficha ficha = desenfileiraF(&fN);
                        string nome = ficha.nome;
                        int idade = ficha.idade;
                        char tipo = ficha.tipo;
                        char quadroClinico = ficha.quadroClinico;
                        if(tipo == 'S')
                        {
                            empilhaP(&pANIMALS, ficha);
                        }
                        else
                        {
                            empilhaP(&pANIMALD, ficha);
                        }
                        contAtendimentosPrioritarios = 0;
                        cout<<"O Paciente " << nome << " foi atendido."<<endl;
                    }
                }else if(vaziaF(&fN) && vaziaF(&fP))
                {
                    cout<<"N�o h� nenhum paciente na espera para ser atendido! "<<endl;
                }
            }
        }
    else if(menu == 3)
    {

        if(!vaziaF(&fP))
        {
        cout<<"Pacientes em Estado Grave: "<<endl;
        NoFila *no = fP.inicio;

        cout << "----------------------------" << endl;

        while (no != NULL) //fa�a enquanto (no != NULL)
        {
            cout << "Nome: " << no->dado.nome << endl;
            cout << "Idade: " << no->dado.idade << endl;
            cout << "Tipo: " << testar_Tipo(no->dado.tipo) << endl;
            cout << "Quadro Cl�nico: " << testar_QC(no->dado.quadroClinico) << endl;
            cout << "----------------------------" << endl;
            no = no->prox;

            //if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                //cout << ", ";
        }
        }

        if(!vaziaF(&fN))
        {
        cout<<"Pacientes em Estado Est�vel: "<<endl;
        NoFila *no = fN.inicio;
        cout << "----------------------------" << endl;
        while (no != NULL) //fa�a enquanto (no != NULL)
        {
            cout << "Nome: " << no->dado.nome << endl;
            cout << "Idade: " << no->dado.idade << endl;
            cout << "Tipo: " << testar_Tipo(no->dado.tipo) << endl;
            cout << "Quadro Cl�nico: " << testar_QC(no->dado.quadroClinico) << endl;
            cout << "----------------------------" << endl;
            no = no->prox;

            //if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                //cout << ", ";
        }


       }

    }
    else if(menu == 4)
    {
        Fila fAux;
        int contPrioritaria=0;
        int contNormal=0;
        int contDomestico=0;
        int contTotal=0;

        while(!vaziaF(&fP))
        {
            Ficha ficha = desenfileiraF(&fP);
            contPrioritaria++;
            if(ficha.tipo == 'D')
                contDomestico++;
            contTotal++;
            enfileiraF(&fAux, ficha);
        }
        while(!vaziaF(&fAux))
        {
            Ficha ficha = desenfileiraF(&fAux);
            enfileiraF(&fP, ficha);
        }

        /////////////////////////////

        while(!vaziaF(&fN))
        {
            Ficha ficha = desenfileiraF(&fN);
            contNormal++;
            if(ficha.tipo == 'D')
                contDomestico++;
            contTotal++;

            enfileiraF(&fAux, ficha);
        }
        while(!vaziaF(&fAux))
        {
            Ficha ficha = desenfileiraF(&fAux);
            enfileiraF(&fN, ficha);
        }

        cout<<"Quantidade Total de Fichas: "<< contTotal <<endl;

        float porc = (float)(contTotal - contNormal) / contTotal;

        cout<<"Porcentagem de animais com quadro cl�nico grave: " << porc << "%" <<endl;

        cout<<"Total de animais dom�sticos: "<< contDomestico <<endl;







    }
    else if(menu == 5)
    {
        Pilha pCopia;
        Pilha pCopia2;
        if(!vaziaP(&pANIMALS))
        {
            cout<<"-> Animais Selvagens atendidos: "<<endl;
            while(!vaziaP(&pANIMALS))
            {
                Ficha ficha = desempilhaP(&pANIMALS);
                empilhaP(&pCopia, ficha);
            }
            while(!vaziaP(&pCopia))
            {
                Ficha ficha = desempilhaP(&pCopia);
                cout<<"----------------------------------"<<endl;
                cout << "Nome: " << ficha.nome << endl;
                cout << "Idade: " << ficha.idade << endl;
                cout << "Tipo : " << testar_Tipo(ficha.tipo) << endl;
                cout << "Quadro Cl�nico: " << testar_QC(ficha.quadroClinico) << endl;
                cout<<"----------------------------------"<<endl;
                empilhaP(&pANIMALS, ficha);
            }
        }

        ////////////////////////////////

        if(!vaziaP(&pANIMALD))
        {
            cout<<"-> Animais Dom�sticos atendidos: "<<endl;
            while(!vaziaP(&pANIMALD))
            {
                Ficha ficha = desempilhaP(&pANIMALD);
                empilhaP(&pCopia, ficha);
            }
            while(!vaziaP(&pCopia))
            {
                Ficha ficha = desempilhaP(&pCopia);
                cout<<"----------------------------------"<<endl;
                cout << "Nome: " << ficha.nome << endl;
                cout << "Idade: " << ficha.idade << endl;
                cout << "Tipo : " << testar_Tipo(ficha.tipo) << endl;
                cout << "Quadro Cl�nico: " << testar_QC(ficha.quadroClinico) << endl;
                cout<<"----------------------------------"<<endl;
                empilhaP(&pANIMALD, ficha);
            }
        }
    }
    else if(menu == 6)
    {
        char pilha;

        while(pilha != 'S' && pilha != 's' && pilha != 'd' && pilha != 'D')
        {
        cout<<"Voc� deseja remover um elemento de qual pilha? (S - Animais Selvagens | D - Animais Dom�sticos)"<<endl;
        cin>>pilha;
        }

        if(pilha == 'S' || pilha == 's')
        {
            Ficha ficha = desempilhaP(&pANIMALS);
            cout<<"Paciente " << ficha.nome << " removido da fila dos Selvagens. " << endl;
        }
        else
        {
            Ficha ficha = desempilhaP(&pANIMALD);
            cout<<"Paciente " << ficha.nome << " removido da fila dos Dom�sticos. " << endl;
        }

    }
    else if(menu == 7)
    {
        Pilha pAux;
        Pilha pCopia;
        Pilha pCopia2;
        Ficha pacienteMaisNovo;

        int menorIdade = INT_MAX;

        if(!vaziaP(&pANIMALS))
        {
            while(!vaziaP(&pANIMALS))
            {
                Ficha ficha = desempilhaP(&pANIMALS);
                empilhaP(&pAux, ficha);
                empilhaP(&pCopia, ficha);
            }
        }
        if(!vaziaP(&pANIMALD))
        {
            while(!vaziaP(&pANIMALD))
            {
                Ficha ficha = desempilhaP(&pANIMALD);
                empilhaP(&pAux, ficha);
                empilhaP(&pCopia2, ficha);
            }
        }
        while(!vaziaP(&pAux))
        {
            Ficha ficha = desempilhaP(&pAux);
            if(ficha.quadroClinico == 'G' && ficha.idade < menorIdade)
            {
                pacienteMaisNovo = ficha;
            }
        }
        cout<<"------------------------------"<<endl;
        cout<<"Nome: " << pacienteMaisNovo.nome<<endl;
        cout<<"Idade: " << pacienteMaisNovo.idade<<endl;
        cout<<"------------------------------"<<endl;

        /////////////////////
        while(!vaziaP(&pCopia))
        {
            Ficha ficha = desempilhaP(&pCopia);
            empilhaP(&pANIMALS, ficha);
        }
        while(!vaziaP(&pCopia2))
        {
            Ficha ficha = desempilhaP(&pCopia2);
            empilhaP(&pANIMALD, ficha);
        }
    }




}
}
