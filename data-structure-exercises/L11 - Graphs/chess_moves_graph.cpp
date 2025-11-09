#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

/**/

struct Pos {
  int x, y;
};

vector<vector<vector<Pos>>> grafo(8, vector<vector<Pos>>(8)); // criando uma matriz tridimensional

// Função para verificar se está dentro do tabuleiro
bool dentro(int x, int y)
{
    return (x >= 0 && x < 8 && y>= 0 && y < 8);
}

void inicializandoGrafoBispo()
{
    // Construindo o grafo para movimentos do bispo
    for (int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            // 4 direções diagonais
            int dx[4] = {1, 1, -1, -1};
            int dy[4] = {1, -1, 1, -1};

            for (int d = 0; d < 4; d++) // percorre as 4 direções possíveis que um vértice possui
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                while(dentro(nx, ny)) //
                {
                    grafo[x][y].push_back({nx, ny});
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }
    }
}
void inicializandoGrafoTorre()
{
    for(int x=0; x<8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            for(int d = 0; d < 4; d++)
            {
                int nx = x += dx[d];
                int ny = y += dy[d];

                while(dentro(nx, ny))
                {
                    grafo[x][y].push_back({nx, ny});
                    nx += dx[d];
                    ny += dy[d];
                }

            }

        }
    }
}void inicializandoGrafoCavalo()
{
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    for(int x=0; x<8; x++)
    {
        for(int y = 0; y < 8; y++)
        {

            for(int d = 0; d < 8; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(dentro(nx, ny))
                {
                    grafo[x][y].push_back({nx, ny});
                }

            }

        }
    }
}
void exibirPossibilidades(int x, int y, string chessPiece)
{
    cout << chessPiece << " em (" << x << ", " << y << ") pode ir para: " << endl;

    for(auto p : grafo[x][y]) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

void lerPosicao(int &x, int &y)
{

   do{

    cout << "Posição Vertical: " << endl;
    cin >> x;

    cout << "Posição Horizontal: " << endl;
    cin >> y;

    if(x > 7 || x < 0 || y > 7 || y < 0)
        cout << "VALORES INVÁLIDOS! " << endl;

    }while(x > 7 || x < 0 || y > 7 || y < 0);
}


int main()
{
   srand(time(NULL));
   setlocale(LC_ALL,"Portuguese");

   int x, y, menu = -1;

   do {

   cout << "0 - Sair" << endl;
   cout << "1 - Exibir Possibilidades Bispo" << endl;
   cout << "2 - Exibir Possibilidades Torre" << endl;
   cout << "3 - Exibir Possibilidades Cavalo" << endl;
   cin >> menu;

   lerPosicao(x, y);

   if(menu == 1)
   {
       grafo = vector<vector<vector<Pos>>>(8, vector<vector<Pos>>(8));
       inicializandoGrafoBispo();
       exibirPossibilidades(x, y, "Bispo");
   }
   else if(menu == 2)
   {
    grafo = vector<vector<vector<Pos>>>(8, vector<vector<Pos>>(8));
    inicializandoGrafoTorre();
    exibirPossibilidades(x, y, "Torre");
   }
   else if(menu == 3)
   {
     grafo = vector<vector<vector<Pos>>>(8, vector<vector<Pos>>(8));
     inicializandoGrafoCavalo();
     exibirPossibilidades(x, y, "Cavalo");
   }
   else
   {
       return 0;
   }

   cout << "\n";

   }while(menu != 0);












}
