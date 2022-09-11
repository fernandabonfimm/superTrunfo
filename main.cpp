// Responsáveis: Fernanda Bonfim Santos - Cod: 2069922, Barbara Diogo - Cod: 2063853
// Acesse o README do projeto, para mais informações.

#include "superTrunfo.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    superTrunfo p, J1, J2;
    carro lista[LIMIT];
    p.Read(lista);
    p.Embaralhar(lista, J1, J2);

    cout << "|***************************************************|" << endl;
    cout << "| Bem-Vindo ao SuperTrunfo da Fernanda e da Barbara |" << endl;
    cout << "|***************************************************|\n\n"
         << endl;

    cout << "|----------------------------------------------------------------|" << endl;
    cout << "| Chamaremos aqui, o usuario atras da maquina de: Jogador Person |" << endl;
    cout << "| Chamaremos aqui, a maquina de: Jogador Machine                 |" << endl;
    cout << "|----------------------------------------------------------------|\n\n"
         << endl;
    p.Jogo(J1, J2);

    return 0;
}
