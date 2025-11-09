#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#include "filacircular-Documentos.h"

/**/

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   Fila p1;

   Fila n1;



    ofstream escrita("entrada.txt", ios::out);

    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";
    escrita << "IMPRIMIRDOC \n";
    escrita << "INICIALIZAR 10 \n";
    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";
    escrita << "IMPRIMIRDOC \n";
    escrita << "TOTALPAG \n";
    escrita << "ENFILEIRARDOC PDF1 10 P \n";
    escrita << "ENFILEIRARDOC PDF2 5 N \n";
    escrita << "ENFILEIRARDOC PDF3 30 N \n";
    escrita << "ENFILEIRARDOC PDF4 3 P \n";
    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";
    escrita << "TOTALPAG \n";
    escrita << "CONSULTAR PDF1 P \n";
    escrita << "CONSULTAR PDF1 N \n";
    escrita << "IMPRIMIRDOC \n";
    escrita << "IMPRIMIRDOC \n";
    escrita << "IMPRIMIRDOC \n";
    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";
    escrita << "TOTALPAG \n";
    escrita << "ENFILEIRARDOC PDF5 10 N \n";
    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";
    escrita << "INICIALIZAR 5 \n";
    escrita << "MOSTRAR P \n";
    escrita << "MOSTRAR N \n";

    escrita.close();

    ifstream leitura("entrada.txt", ios::in);

    string linha;

    while(getline(leitura, linha))
    {
        string operacao;
        char fila;
        string nomeDoc;
        int numPaginas;
        int tam;

        leitura >> operacao;

        if(operacao == "ENFILEIRARDOC")
        {
            leitura >> nomeDoc;
            leitura >> numPaginas;
        }
        else if(operacao == "CONSULTAR")
            leitura >> nomeDoc;

        if(operacao != "IMPRIMIRDOC" && operacao != "TOTALPAG" && operacao != "INICIALIZAR")
        {
            leitura >> fila;
        }
        else if(operacao == "INICIALIZAR")
        {
            leitura >> tam;
        }

        if(operacao == "MOSTRAR")
        {
            if(fila == 'P' && !verificaInicializacaoF(&p1))
                cout<<"ERRO: inicializar fila P "<<endl;
            else if(fila == 'N' && !verificaInicializacaoF(&n1))
                cout<<"ERRO: inicializar fila N "<<endl;
            else if(fila == 'P' && vaziaF(&p1))
                cout<<"Fila vazia "<<endl;
            else if(fila == 'N' && vaziaF(&n1))
                cout<<"Fila vazia " <<endl;
            else
            {
                if(fila == 'N')
                {
                    for(int i= n1.inicio; i < n1.fim; i++)
                    {
                        if(i == (n1.total - 1))
                            cout << n1.dados[i].nome <<endl;
                        else
                            cout << n1.dados[i].nome << ", ";
                    }
                }
                else if(fila == 'P')
                {
                    for(int i=p1.inicio; i < p1.fim; i++)
                    {
                        if(i == (p1.total - 1))
                            cout << p1.dados[i].nome << endl;
                        else
                            cout << p1.dados[i].nome << ", ";
                    }
                }
            }
        }
        else if(operacao == "INICIALIZAR")
        {
            if(verificaInicializacaoF(&p1) || verificaInicializacaoF(&n1))
            {
                destroiF(&p1);
                destroiF(&n1);
            }

            inicializaF(&p1, tam);
            inicializaF(&n1, tam);
            {
                cout<<"As filas P e N foram inicializadas com o tamanho " << tam <<endl;
            }
        }
        else if(operacao == "ENFILEIRARDOC")
        {
            if(!verificaInicializacaoF(&n1) && !verificaInicializacaoF(&p1))
            {
                cout<<"ERRO: Inicializar filas "<<endl;
            }
            else
          {
            if(fila == 'P')
            {
                if(!cheiaF(&p1))
                {
                Documentos doc = {nomeDoc, numPaginas};
                enfileiraF(&p1, doc);
                cout<<"O documento " << nomeDoc << " (" << numPaginas << " páginas) foi adicionado na fila P"<<endl;
                }
                else
                    cout<<"FILA CHEIA"<<endl;
            }
            else if(fila == 'N')
            {
                if(!cheiaF(&n1))
                {
                Documentos doc = {nomeDoc, numPaginas};
                enfileiraF(&n1, doc);
                cout<<"O documento " << nomeDoc << " (" << numPaginas << " páginas) foi adicionado na fila N"<<endl;
                }
                else
                    cout<<"FILA CHEIA"<<endl;
            }
          }
        }
        else if(operacao == "IMPRIMIRDOC")
        {
            if(!verificaInicializacaoF(&p1) && !verificaInicializacaoF(&n1))
            {
                cout<<"ERRO: Inicializar filas P e N"<<endl;
            }
            else
            {
            if(!vaziaF(&p1))
            {
                Documentos doc = desenfileiraF(&p1);
                cout<<"O documento " << doc.nome << " foi impresso. "<<endl;
            }
            else if(!vaziaF(&n1))
            {
                Documentos doc = desenfileiraF(&n1);
                cout<<"O documento " << doc.nome << " foi impresso. "<<endl;
            }
            else if(vaziaF(&p1) && vaziaF(&n1))
            {
                cout<<"NÃO há documentos para imprimir"<<endl;
            }
            }
        }
        else if(operacao == "TOTALPAG")
        {
            int cont=0;
            for(int i=p1.inicio; i<p1.fim; i++)
            {
                cont += p1.dados[i].quantPaginas;
                //cout<<cont<<endl;
            }
            for(int i=n1.inicio; i<n1.fim; i++)
            {
                cont += n1.dados[i].quantPaginas;
                //cout<<cont<<endl;
            }
            cout<<cont << " página(s)"<<endl;
        }
        else if(operacao == "CONSULTAR")
        {
            bool achou = false;

            if(!verificaInicializacaoF(&p1) && !verificaInicializacaoF(&n1))
            {
                cout<<"ERRO: inicializar filas "<<endl;
            }
            else
            {
            if(fila == 'P')
            {
                for(int i=0; i<p1.total; i++)
                {
                    if(nomeDoc == p1.dados[i].nome)
                    {
                        achou = true;
                        break;
                    }
                }
                if(achou)
                {
                    cout<<"O documento " << nomeDoc << " encontra-se na fila P" <<endl;
                }
                else
                    cout<<"O documento " << nomeDoc << " não encontra-se na fila P " <<endl;

            }


        else if(fila == 'N')
        {
            for(int i=0; i<n1.total; i++)
            {
                if(nomeDoc == n1.dados[i].nome)
                {
                    achou = true;
                    break;
                }

            }
            if(achou)
            {
                cout<<"O documento " << nomeDoc << " encontra-se na fila N" <<endl;
            }
            else
                cout<<"O documento " << nomeDoc << " não está na fila N" <<endl;

        }
            }

        }
    }
}






















